#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1e5+5,M=1e4+5;
using ll=long long ;
int n,m,k,cnt;
ll ans=1e18;
struct S{
	int u,v,edge;
} a[N],d[N];
int c[15],b[15][M];
int f[M+15];
bool st[15];
bool C(S a,S b){
	return a.edge<b.edge;
}
int find(int x){
	return f[x]==x?f[x]:f[x]=find(f[x]);
}
ll count(ll sum){
	ll s=sum;
	for(int i=1;i<=cnt;i++) d[i]=a[i];
	for(int i=1;i<=n+k;i++) f[i]=i;
	sort(d+1,d+cnt+1,C);
	for(int i=1;i<=cnt;i++){
		int p=d[i].v,q=d[i].u,e=d[i].edge;
		p=find(p),q=find(q);
		if(p!=q){
			s+=e;
			f[p]=q;
		}
	}
	return s;
}
void dfs(int u,ll sum){
	if(u>k){
		cnt=m;
		for(int i=1;i<=k;i++){
			if(st[i]){
				for(int j=1;j<=n;j++){
					a[++cnt].u=n+i;
					a[cnt].v=j;
					a[cnt].edge=b[i][j];					
				}
			}
		}
		ans=min(ans,count(sum));
		return;
	}
	st[u]=1;
	dfs(u+1,sum+c[u]);
	st[u]=0;
	dfs(u+1,sum);
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].edge;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			if(!j) cin>>c[i];
			else{
				cin>>b[i][j];
			}
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

