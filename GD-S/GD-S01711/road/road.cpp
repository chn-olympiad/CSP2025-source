#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e4+5,M=2e6+5;
ll n,m,k;
ll cnt;
ll head[N];
ll c[15],d[N];
ll a[15][N];
struct node{
	ll to,nxt,val;
}e[M<<1];
struct y{
	ll x,y,w;
}s[M];
struct yy{
	ll y,w;
}tmp;
void add(ll u,ll v,ll w){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	e[cnt].val=w;
	e[++cnt].to=u;
	e[cnt].nxt=head[v];
	e[cnt].val=w;
}
bool cmp(y a,y b){
	return a.w<b.w;
}
//int dis[N];
//queue<int> q;
//void ks(){
//	for(int i=1;i<=n;i++){
//		dis[i]=INT_MAX;
//	}
//	dis[1]
//	while(!q.empty()){
//		
//	}
//}
bool vis[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++){
		d[i]=INT_MAX;
	}
	for(ll i=1;i<=m;i++){
		cin>>s[i].x>>s[i].y>>s[i].w;
		add(s[i].x,s[i].y,s[i].w);
	}
	if(k==0){
		sort(s+1,s+1+m,cmp);
//		for(ll i=1;i<=m;i++){
//			cout<<s[i].w<<" ";
//		}
//		ks();
	}
	bool f=0;
	for(ll i=1;i<=k;i++){
		cin>>c[i];
//		int sum=0;
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
			if(!a[i][j]){
//				sum++;
			}
			d[j]=min(d[j],a[i][j]);
		}
//		if(sum==n){
//			f=1;
//		}
	}
//	if(f==1){
		ll sum=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=k;j++){
				if(a[j][i]==d[i]){
					if(vis[j]){
						break;
					}
					vis[j]=1;
					sum+=c[j];
				}
			}
//			cout<<d[i]<<" ";
			sum+=d[i];
		}
		cout<<sum<<'\n';
//	}
	return 0;
} 
