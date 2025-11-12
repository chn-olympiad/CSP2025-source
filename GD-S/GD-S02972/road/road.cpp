#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20,M=1e6+10;
int n,m,k,f[N],sz[N];
ll a[20][N],c[20],ans,as;
priority_queue<pair<ll,pair<int,int> > > q,p[20];
int get(int x){
	return (f[x]==x?x:f[x]=get(f[x]));
}
void dfs(int x,int s){
	if(x>k){
		for(int i=1;i<=n+s;i++){
			f[i]=i;
			sz[i]=1;
		}
		p[x]=q;
		int d=0;
		ll zs=as;
		while(d<n+s){
			int x=q.top().second.first,y=q.top().second.second;
			ll z=-q.top().first;
			q.pop();
			x=get(x);
			y=get(y);
			if(x!=y){
				as+=z;
				f[x]=y;
				sz[y]+=sz[x];
				d=max(d,sz[y]);
			}
		}
		ans=min(ans,as);
		q=p[x];
		as=zs;
		return ;
	}
	p[x]=q;
	dfs(x+1,s);
	as+=c[x];
	for(int i=1;i<=n;i++){
		q.push({-a[x][i],{n+s+1,i}});
	}
	dfs(x+1,s+1);
	q=p[x];
	as-=c[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		ll z;
		cin>>x>>y>>z;
		q.push({-z,{x,y}});
	}
	ans=1e18;
	int kk=0;
	for(int i=1;i<=k;i++){
		cin>>c[++kk];
		ll mn=1e18,w=0;
		for(int j=1;j<=n;j++){
			cin>>a[kk][j];
			if(a[kk][j]<mn){
				mn=a[kk][j];
				w=j;
			}
		}
		if(mn==0&&c[kk]==0){
			for(int j=1;j<=n;j++){
				if(j==w) continue;
				q.push({-a[kk][j],{w,j}});
			}
			kk--;
		}
	}
	k=kk;
	dfs(1,0);
	cout<<ans;
	return 0;
}
