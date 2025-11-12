#include<bits/stdc++.h>
#define ll long long
#define mkp make_pair
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define tfile(x) freopen(x".in","r",stdin)
#define dtfile(x) freopen(x".in","w",stdout)
using namespace std;
const int N=10015,M=15;
const ll INF=1e15;
int n,m,k,cnt,f[N];
ll ans,mn[M][N],w[M][N],c[N];
struct node{
	int x,y;
	bool operator < (node A) const{
		return 0;
	}
};
priority_queue<pair<ll,node> > q;
int get(int x){return f[x]==x?x:f[x]=get(f[x]);}
int main(){
	file("road");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k,cnt=n;
	for(int i=1,x,y,w;i<=m;i++)cin>>x>>y>>w,q.push(mkp(-w,(node){x,y}));
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>w[i][j],mn[i][j]=w[i][j];
	}
	for(int i=1;i<=n+k;i++)f[i]=i;
	while(!q.empty()&&cnt>1){
		int x=q.top().second.x;
		int y=q.top().second.y;
		ll wx=-q.top().first;
		x=get(x),y=get(y),q.pop();
		if(x==y)continue;
		ll W=INF;
		int o=0;
		for(int i=1;i<=k;i++)if(mn[i][x]+mn[i][y]+c[i]<W)W=mn[i][x]+mn[i][y]+c[i],o=i;
//		cout<<x<<' '<<y;
		if(W<wx){
//			cout<<' '<<o; 
			ans+=W,f[o+n]=x;
			for(int i=1;i<=n;i++)q.push(mkp(-w[o][i],(node){o+n,i}));
		}else ans+=wx;
//		cout<<'\n';
		f[x]=y,cnt--;
		for(int i=1;i<=k;i++)mn[i][y]=min(mn[i][y],mn[i][x]); 
	}
	cout<<ans;
	return 0;
}
