#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
const ll inf=2e9;
vector<int>ve[10004];
ll t[10004][10004];
bool f[10004][10004];
ll fix[15][10004];
struct node{
	ll pos,s,cnt;
	bool ve[10];
};
ll whazdis[1000006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		whazdis[i]=w;
		ve[u].push_back(v);
		ve[v].push_back(u);
		f[u][v]=1,f[v][u]=1;
		t[u][v]=w,t[v][u]=w;
	}
	if(k==0){
		sort(whazdis+1,whazdis+1+m);
		ll sum=0;
		for(int i=1;i<=n-1;i++)sum+=whazdis[i];
		printf("%lld",sum);
		return 0;
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			scanf("%lld",&fix[i][j]);
	node x;
	for(int i=1;i<=n;i++)x.ve[i]=0;
	x.pos=1,x.s=0,x.ve[1]=1,x.cnt=1;
	queue<node>q;
	q.push(x);
	ll ans=inf;
	while(!q.empty()){
		x=q.front();
		cout<<x.pos<<'\n';
		q.pop();
		for(int i=0;i<ve[x.pos].size();i++){
			node y;
			y.pos=ve[x.pos][i];
			if(x.ve[y.pos]==0)y.s=x.s+t[x.pos][y.pos];
			y.cnt=x.cnt+1;
			for(int j=1;j<=n;j++)y.ve[j]=x.ve[j];
			y.ve[y.pos]=1;
			if(y.cnt==n){
				ans=min(ans,y.s);
				continue;
			}
			q.push(y);
		}
	}
	printf("%lld",ans);
	return 0;
}
