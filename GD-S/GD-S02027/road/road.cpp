#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll w,v;
};
ll n,m,k,dw[20],dis[10100],ans=1e18,v[20];
vector<node>a[10100];
priority_queue<node>q;
bool operator<(node x,node y){
	return x.w>y.w;
}
int main(){
	ll i,j;
	node x,y;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&j,&x.v,&x.w);
		a[j].push_back(x);
		swap(j,x.v);
		a[j].push_back(x);
	}
	for(i=1;i<=k;i++){
		scanf("%lld",&dw[i]);
		for(j=1;j<=n;j++){
			scanf("%lld",&x.w);
			x.v=j;
			a[n+i].push_back(x);
			x.v=n+i;
			a[j].push_back(x);
		}
	}
	for(i=0;i<=(1<<k)-1;i++){
	ll cnt=0;
	x.v=1; x.w=0; 
	for(j=1;j<=n+k;j++) dis[j]=1e18;
	for(j=1;j<=k;j++) v[j]=0;
	for(j=1;j<=k;j++)
	if((1<<(j-1)&i)>0)
	cnt+=dw[j],v[j]=1;
	q.push(x);
	while(!q.empty()){
		x=q.top();
		q.pop();
		if(dis[x.v]!=1e18) continue;
		dis[x.v]=x.w;
		cnt+=x.w;
		if(cnt>=ans) break;
		for(j=0;j<a[x.v].size();j++){
			if(a[x.v][j].v>n) 
			if(v[a[x.v][j].v-n]==0)continue;
			y.v=a[x.v][j].v;
			y.w=a[x.v][j].w;
			q.push(y);
		}
	}
	while(!q.empty()) q.pop();
	ans=min(ans,cnt);
    }
    cout<<ans;	
}
