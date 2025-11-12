#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m,k,a,b,c,sum=1e9,f,na,d[1000001],vis[1000001],gh,hj;
struct node{
	LL v,w;
};
vector <node> e[1000001];
void dis(LL s){
	memset(vis,0,sizeof vis);
	priority_queue<pair<LL,LL> > q;
	for(LL i=1;i<=n+k;i++){
		d[i]=1e9;
	}
	q.push({0,s});
	d[s]=0;
	while(!q.empty()){
		LL ne=-q.top().first;
		LL t=q.top().second;
		q.pop();
		if(ne>d[t]) continue;
		for(auto it:e[t]){
			LL v=it.v;
			LL w=it.w;
			if(d[v]>w+d[t]){
				d[v]=w+d[t];
				if(vis[v]==0) q.push({-d[v],t}),vis[t]=1;
			}
		}
		
	}
	f=0;
	for(LL i=1;i<=n;i++){
		f+=d[i];
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(LL i=1;i<=m;i++){
		cin>>a>>b>>c;
		e[a].push_back({b,c});
		e[b].push_back({a,c});
	}
	if(k==0){
		for(LL i=1;i<=n;i++){
			dis(i);
			sum=min(sum,f);
		}
		cout<<sum;
		return 0;
	}
	for(LL i=1;i<=k;i++){
		cin>>gh;
		for(LL j=1;j<=n;j++){
			cin>>hj;
			e[n+i].push_back({j,gh+hj});
		    e[j].push_back({n+i,gh+hj});
		}
		for(LL i=1;i<=n;i++){
			dis(i);
			sum=min(sum,f);
		}
	}
	cout<<sum;
	return 0;
}
