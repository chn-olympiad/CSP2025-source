//所以，k=10 有什么用
//话说为啥这样能过阳历 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=987654329991;
struct edge{
	int u,v,val,is,need;
}e[2000006];//两端，费用，是否是添加的，是否真的需要 
int fa[20004],c[50];
struct node{
	int id,val;
}a[15][10004];
bool cmp1(edge a1,edge a2){
	return a1.val<a2.val;
}
bool cmp2(edge a1,edge a2){
	return a1.is<a2.is;
}
bool cmp3(edge a1,edge a2){
	return a1.need<a2.need;
}
int find_(int x){
	if(fa[x]==x)return fa[x];
	else {
		int res=find_(fa[x]);
		fa[x]=res;
		return res;
	}
}
void merge_(int x,int y){
	int fx=find_(x),fy=find_(y);
	fa[fx]=fa[fy];
}
int mscs(int arrn,int arrm){
	for(int i=1;i<=arrn;i++)fa[i]=i;
	sort(e+1,e+arrm+1,cmp1);
	int res=0;
	for(int i=1;i<=arrm;i++){
		if(find_(e[i].u)==find_(e[i].v)){
			e[i].need=1;//不需要 
			continue;
		}
		merge_(e[i].u,e[i].v);
		res+=e[i].val;
		e[i].need=0;//需要 
	}
	return res;
}
int cnt;
int newcnt[15],is_newk;
signed main(){
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].val;
		e[i].is=0;
	}
	int buzhidao=mscs(n,m);
	if(k==0){
		cout<<buzhidao<<endl;
		return 0;
	}
	sort(e+1,e+m+1,cmp3);
	int w=1;
	while(e[w].need==0)w++;
	m=w;//去掉不需要的 
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag=0;
		cnt=m;
		for(int j=1;j<=n;j++){
			cnt++;
			e[cnt].u=n+1;
			e[cnt].v=j;
			cin>>e[cnt].val;
			e[cnt].is=1;
		}
		buzhidao=mscs(n+1,cnt);
		sort(e+1,e+cnt+1,cmp3);
		int w=0;
		for(int j=1;j<=cnt;j++){
			if(e[j].is==1&&e[j].need==0){
				w++;
				a[i][w].id=e[j].v;
				a[i][w].val=e[j].val;
			}
		}
		newcnt[i]=w;
		sort(e+1,e+cnt+1,cmp2);
	}
	int num=1<<k;//开始暴力 
	for(int i=1;i<=num;i++){
		cnt=m;
		int arr=0;
		for(int j=0;j<=k-1;j++){
		//	int ddd=(i>>j)&1;
		//	cout<<ddd<<endl;
			if((i>>j)&1){
		//		cout<<j+1<<endl;
				for(int tmp=1;tmp<=newcnt[j+1];tmp++){
					cnt++;
					e[cnt].u=n+j+1;
					e[cnt].v=a[j+1][tmp].id;
					e[cnt].val=a[j+1][tmp].val;
					e[cnt].is=1;
				}
				arr+=c[j+1];
			}
		}
		arr+=mscs(n+11,cnt);
		sort(e+1,e+cnt+1,cmp2);
		ans=min(ans,arr);
	}
	cout<<ans<<endl;
	return 0;
}
