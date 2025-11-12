#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXC=15;
const int MAXM=1025;
const int MAXN=15005;
const int MAXK=2000005;
int n,m,k;
struct stu{
	int u;
	int v;
	int w;
};
stu b[MAXK];
stu a[MAXK];
bool cmp(stu a,stu b){
	return a.w<b.w;
}
int ans[MAXM];
int c[MAXC][MAXN];
int fa[MAXM][MAXN];
int find(int x,int i){
	if(fa[i][x]==x){
		return x;
	}
	return fa[i][x]=find(fa[i][x],i);
}
void merge(int x,int y,int i){
	x=find(x,i);
	y=find(y,i);
	if(x==y){
		return;
	}
	fa[i][y]=x;
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	sort(b+1,b+m+1,cmp);
	int N=(1<<k)-1;
	for(int i=0;i<=N;i++){
		for(int j=1;j<=n+k;j++){
			fa[i][j]=j;
		}
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u=find(b[i].u,0);
		int v=find(b[i].v,0);
		if(u==v){
			continue;
		}
		ans[0]+=b[i].w;
		a[++cnt]=b[i];
		merge(u,v,0);
	}
	//cout<<"a"<<endl;
	int o=n;
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		o++;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			a[++cnt]={j,o,c[i][j]};
		}
	} 
	//cout<<"b="<<cnt<<endl;
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=k;j++){
			if((i&(1<<(j-1)))){
				ans[i]+=c[j][0];
			}
		}
	}
//	for(int i=1;i<=N;i++){
//		cout<<"oo="<<i<<" "<<ans[i]<<endl;
//	}
	//cout<<"c"<<endl;
	for(int i=1;i<=cnt;i++){
		int u=a[i].u;
		int v=a[i].v;
		//cout<<"i="<<i<<" "<<u<<" "<<v<<" "<<a[i].w<<endl; 
		for(int j=1;j<=N;j++){
			if(v>n){
				if((j&(1<<(v-n-1)))==0){
					continue;
				}
				if(find(u,j)==find(v,j)){
					continue;
				}
				ans[j]+=a[i].w;
				merge(u,v,j);
			}else{
				if(find(u,j)==find(v,j)){
					continue;
				}
				ans[j]+=a[i].w;
				merge(u,v,j);
			}
		}
	}
	//cout<<"d"<<endl;
	int all=LONG_LONG_MAX;
	for(int i=0;i<=N;i++){
		//cout<<"i="<<i<<" "<<ans[i]<<endl;
		all=min(all,ans[i]);
	}
	cout<<all;
	return 0;
}
