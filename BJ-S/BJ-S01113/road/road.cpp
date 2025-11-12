#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,M=2e6+5;
int n,m,k;
int c[N];
int g[15][N];
ll ans=2e9;
struct node{
	int u,v,w;
}p[M],l[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[N];
bool a[15];
int zu(int x){
	if(x!=fa[x]){
		int u=zu(fa[x]);
		fa[x]=u;
		return u;
	}
	return x;
}
void merge(int x,int y){
	int u=zu(x),v=zu(y);
	if(u!=v) fa[u]=v;
}
ll check(){
	//cout<<"\n";
	int _n=n,_m=m;
	for(int i=1;i<=_m;i++) l[i]=p[i];
	for(int i=1;i<=k;i++){
		if(a[i]){
	//		cout<<i<<"\n";
			_n++;
			for(int j=1;j<=n;j++){
				l[++_m]={_n,j,g[i][j]};
			}
		}
	}
	for(int i=1;i<=_n;i++){
	//	cout<<l[i].u<<" "<<l[i].v<<" "<<l[i].w<<"\n";
		fa[i]=i;
	}
	ll sum=0,cnt=0;
	sort(l+1,l+_m+1,cmp);
	for(int i=1;i<=_m;i++){
		int a=l[i].u,b=l[i].v,c=l[i].w;
		if(zu(a)!=zu(b)){
			merge(a,b);
			sum+=c;
			cnt++;
			if(cnt==_n-1) break;
		}
	}
	return sum;
}
void dfs(int d,ll sum){
	if(d==k){
		ans=min(ans,check()+sum);
		return;
	}
	a[d+1]=0;
	dfs(d+1,sum);
	a[d+1]=1;
	dfs(d+1,sum+c[d+1]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	//cout<<9;
	bool bb=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) bb=0;
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	if(!bb) dfs(0,0);
	else{
		for(int i=1;i<=k;i++) a[i]=1;
		cout<<check();
		return 0;
	}
	cout<<ans;
	return 0;
}
