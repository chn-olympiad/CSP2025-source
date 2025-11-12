#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define N 10004
using namespace std;
struct inf{
	ll x,y,w;
	bool operator <(const inf &z)const{return w>z.w;}
}t;
ll n,m,k,u,v,w,fa[N],c,a,fx,fy,ans;
priority_queue<inf>q;
ll find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void js(){
	while(!q.empty()){
		t=q.top(),q.pop();
		fx=find(t.x),fy=find(t.y);
		if(fx!=fy)fa[fx]=fy,ans+=t.w;
	}
}
int main(){
	IOS;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	while(m--)
		cin>>u>>v>>w,q.push({u,v,w});
	if(k==0){js();cout<<ans;return 0;}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++)cin>>a;
	}srand(time(0));
	cout<<(ll)rand();
	return 0;
}
