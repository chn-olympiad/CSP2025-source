#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define mn 10101
using namespace std;
long long n,m,k,u,v,ww,c,a,fa[mn],sz,ans,vis[mn];
int now;
vector<int> e[mn],w[mn];
struct nd{
	long long u,v,d;
	friend bool operator < (nd x,nd y){
		return x.d>y.d;
	}
}f;
priority_queue<nd> q;
int fd(int x){
	if(x==fa[x]) return x;
	return fa[x]=fd(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&u,&v,&ww);
		q.push({u,v,ww});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a);
			q.push({j,n+i,a});
		}
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<n+k;i++){
		while(fd(q.top().u)==fd(q.top().v)) q.pop();
		ans+=q.top().d;
		fa[fd(q.top().u)]=fd(q.top().v);
		q.pop();
	}
	cout<<ans<<endl;
	return 0;
}
