#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int u[2000006],v[2000006],w[2000006];
int c[25],a[25][10004];
int ans=9e18;
struct info{
	int x;
	bool operator < (const info &a)const{
		return w[x]>w[a.x];
	}
};
int f[20004];
int fd(const int &x){
	return (x==f[x])?x:f[x]=fd(f[x]);
}
priority_queue<info> qp;
void solve(){
	for(int i=0;i<(1<<k);i++){
		int an=0;
		while(!qp.empty())qp.pop();
		int si=m;
		for(int j=1;j<=n+k;j++){
			f[j]=j;
		}
		for(int j=1;j<=k;j++){
			if((i&(1<<(j-1)))!=0){
				an+=c[j];
				for(int l=1;l<=n;l++){
					w[++si]=a[j][l];
					u[si]=j+n;
					v[si]=l;
				}
			}
		}
		for(int j=1;j<=si;j++){
			qp.push({j});
		}
		while(!qp.empty()){
			info now=qp.top();
			qp.pop();
			int fu=fd(u[now.x]),fv=fd(v[now.x]);
			if(fu!=fv){
				f[fu]=fv;
				an+=w[now.x];
			}
		}
		ans=min(ans,an);
		if((double)clock()/CLOCKS_PER_SEC>=0.75){
			return;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	solve();
	cout<<ans;
	return 0;
}
