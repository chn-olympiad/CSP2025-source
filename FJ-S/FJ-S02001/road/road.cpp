#include<bits/stdc++.h>
using namespace std;
struct node{
	long long id,dis;
}x;
priority_queue<node> q[1000005];
bool operator<(node a,node b){
	return a.dis>b.dis;
}
long long  p[1000005];
long long n,m,k,ans1=0,e=1,l,sum=0,sum1=0;

bool f[10005];
int main(){
	memset(p,10000,sizeof(p));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,dis;
		cin>>u>>v>>dis;
		q[u].push({v,dis});
		q[v].push({u,dis});
		p[v]=min(p[v],dis);
		p[u]=min(p[u],dis);
	}
	for(int i=1;i<=m;i++){
		sum+=p[i];
	}
	l=n;
	for(int i=1;i<=k;i++){
		long long  c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int dis;
			cin>>dis;
			q[n+e].push({j,dis});
			q[j].push({n+e,dis});
			if(p[j]>dis&&j!=1){
				sum1+=p[j]-dis;
			}
		}	
		e++;
		if(sum1>c){
			ans1+=c;
			l+=1;
		}
	}
	f[1]=1;
	for(int i=0;i<n;i++){
		int mini=1e9,mins;
		for(int j=1;j<=l;j++){
			if(!f[j]) continue;
			while(!q[j].empty()&&f[q[j].top().id]) q[j].pop();
			while(q[j].top().id>l) q[j].pop();
			if(q[j].empty()) continue;
			if(q[j].top().dis<mini){
				mini=q[j].top().dis;
				mins=j;
			}
		}
		if(mini==1e9){
			continue;
		}
		f[q[mins].top().id]=1;
		ans1+=q[mins].top().dis;
		q[mins].pop();
	}
	cout<<ans1;
	return 0;
}
