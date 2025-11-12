#include<bits/stdc++.h>
#define ll long long
using namespace std; 	
const int N=1e6+60,M=1e6+60;
struct node{
	ll v,u,val;
	bool flag;
	bool operator >(const node&x)const{
		return val>x.val;
	}
};
ll n,m,k,u[N],v[N],w[N],fa[N],vis[N],sum,op,we,cntm,yu;
priority_queue<node,vector<node>,greater<node>>q,q1,q2;
ll c[N],x[50][N],ans=1e15,cnt;
ll find(ll x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void Add(ll u,ll v,ll val){
	ll X=find(u),Y=find(v);
	if(X!=Y){
		fa[X]=Y;
		sum+=val,cnt++;
	}
}
void solve(){
	for(int z=0;z<(1<<k);z++){sum=0,cnt=0;op=0,we=z,yu=0;
		while(!q.empty()) q.pop();
		for(int i=1;i<=n+k;i++) fa[i]=i,vis[i]=0;
		while(!q2.empty()){
			q1.push(q2.top());
			q2.pop();
		}
		for(int i=1;i<=k;i++)
			if((z>>(i-1))&1)  {
				for(int j=1;j<=n;j++)  {
					yu++;
					q.push({i+n,j,x[i][j]+c[i],0});
				}
				op++;
			}
		while(cnt<n-1+op){
			if(!q.empty()){
				node t=q.top();
				if(t.v>n&&vis[t.v]) t.val-=c[t.v-n];
				if(t.val<q1.top().val){
					if(t.v>n&&!vis[t.v]) vis[t.v]=1;
					q.pop();			
					Add(t.u,t.v,t.val);	
				}
				else if(!q1.empty()){
					q2.push(q1.top());
					Add(q1.top().u,q1.top().v,q1.top().val);
					q1.pop();
				}	
				else {
					if(t.v>n&&!vis[t.v]) vis[t.v]=1;
					q.pop();			
					Add(t.u,t.v,t.val);						
				}			
			}
			else {
				q2.push(q1.top());
				Add(q1.top().u,q1.top().v,q1.top().val);
				q1.pop();				
			}
		} 
		ans=min(ans,sum);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
		q1.push({u[i],v[i],w[i],0});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) 
			scanf("%lld",&x[i][j]);
	}
	solve();
	printf("%lld",ans);
	return 0;
}
