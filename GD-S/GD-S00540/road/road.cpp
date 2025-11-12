#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+7,M=2e6+7;
struct node{
	ll x,y,w;
}e[M];
string s,t;
ll a[N],vis[12],fa[N];
ll n,m,k,q,ans,cnt,sum,tot,opt,mx=-1e9,l,r,mid,fl,x,y,z,w;
ll rd(){
	char c=getchar();ll x=0;
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
void init(){
	for(ll i=1;i<=n+k;i++)fa[i]=i;
}
ll find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(ll x,ll y){
	fa[find(x)]=find(y);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(ll i=1;i<=m;i++)e[i]={rd(),rd(),rd()};
	for(ll i=1;i<=k;i++){
		a[i+n]=rd();
		for(ll j=1;j<=n;j++){
			x=rd(),e[++m]={i+n,j,x};
		}
		if(a[i+n])fl=1;
	}
	sort(e+1,e+1+m,cmp);
//	if(!fl){
//		init(),cnt=sum=0,tot=n+k;
//		for(ll i=1;i<=m;i++){
//			if(cnt==tot-1)break;
//			x=e[i].x,y=e[i].y,w=e[i].w;
//			if(find(x)==find(y))continue;
//			merge(x,y),cnt++,sum+=w;
//		}
//		cout<<min(ans,sum),exit(0);
//	}
	ans=1e18;
	for(ll j=0;j<(1<<k);j++){
		init(),cnt=sum=0,tot=n+__builtin_popcount(j);
		for(ll i=0;i<k;i++){
			vis[i+1]=((j>>i)&1);
			sum+=vis[i+1]*a[i+n+1];
		}
		for(ll i=1;i<=m;i++){
			if(cnt==tot-1)break;
			x=e[i].x,y=e[i].y,w=e[i].w;
			if((x>n&&!vis[x-n])||find(x)==find(y))continue;
			merge(x,y),cnt++,sum+=w;
		}
		ans=min(ans,sum);//cout<<sum<<" "; 
	}
	cout<<ans;
	return 0;
}
