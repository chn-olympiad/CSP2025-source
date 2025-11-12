#include<bits/stdc++.h>
#define int long long int 
using namespace std;
const int N=5e6+10;
struct Node{
	int u,v,w,next;
}a[N];
int n,m,k,head[N],cnt,vis[N],b[15][N],c[15],fa[N],num,ans,d[N],dian;
void init(int n){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
void merge(int x,int y){
	int xx=find(x),yy=find(y);
	fa[xx]=yy;
}
void add(int u,int v,int w){
	a[++cnt].next=head[u];
	head[u]=cnt;
	a[cnt].v=v;
	a[cnt].u=u;
	a[cnt].w=w;
}
bool cmp(Node x,Node y){
	return x.w<y.w;
}
void dfs(int pos,int shu,int xuan,int fei){
	if(shu==k){
//		if(xuan==0) return ;
		init(n+k);
		int numm=0,anss=0;
		sort(a+1,a+1+cnt,cmp);
		for(int i=1;i<=m*10;i++){
			if(find(a[i].u)!=find(a[i].v)){
//				cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"\n";
				anss+=a[i].w;
				dian=max(a[i].w,dian);
				merge(a[i].u,a[i].v);
				numm++;
			}
			if(numm==n+xuan-1){
				break;
			}
		}
//		cout<<ans<<" "<<xuan<<endl;
		ans=min(anss+fei,ans);
//		cout<<ans<<endl;
		return ;
	}
	dfs(pos+1,shu+1,xuan,fei);
	if(d[pos]+c[pos]<dian){
//		cout<<"+++\n";
		for(int i=1;i<=n;i++){
			add(pos+n,i,b[pos][i]);
		}
		dfs(pos+1,shu+1,xuan+1,fei+c[pos]);
	}
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	init(n);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	sort(a+1,a+1+cnt,cmp);
	num=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
//			cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"\n";
			ans+=a[i].w;
			dian=max(a[i].w,dian);
			merge(a[i].u,a[i].v);
			num++;
		}
		if(num==n-1){
			break;
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
//	cout<<ans<<endl;
//	cout<<"***\n";
	for(int i=1;i<=k;i++){
		cin>>c[i];
		d[i]=INT_MAX;
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
			d[i]=min(d[i],b[i][j]);
		}
	}
//	for(int i=1;i<=k;i++){
//		cout<<c[i]<<" ";
//	}
//	cout<<endl;
	dfs(1,0,0,0);
	cout<<ans;
}
//Ren5Jie4Di4Ling5%
