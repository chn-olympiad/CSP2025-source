#include<bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define of(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=13000;
const int M=3100000;
ll ans=1e18+10;
struct qwq{
	int u,v;
	ll w;
	int id;
}edge[M];
int len=0;
bool vis[N];
bool cmp(qwq a1,qwq a2){
	return a1.w<a2.w;
}
int fa[N];
int fi(int u){
	if(fa[u]==u)return u;
	return fa[u]=fi(fa[u]);
}
int n,m,k;
ll c[N];
ll kr(int x){
	int ttg=0;
	int itd=0;
	ll sum=0;
	while(x){
		itd++;
		if(x%2==1){
			vis[itd]=1;
			sum+=c[itd];
			ttg++;
		}
		else vis[itd]=0;
		x/=2;
	}
	int tot=0;
	fo(i,1,len){
		if(vis[edge[i].id]==0)continue;
		int u=edge[i].u,v=edge[i].v;
		ll w=edge[i].w;
		int tu=fi(u),tv=fi(v);
		if(tu!=tv){
			fa[tu]=tv;
			sum+=w;
			tot++;
		}
		if(tot==n+ttg-1)break;
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	vis[0]=1;
	fo(i,1,m){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	len=m;
	fo(i,1,k){
		cin>>c[i];
		fo(j,1,n){
			len++;
			cin>>edge[len].w;
			edge[len].u=i+n,edge[len].id=i;
			edge[len].v=j;
		}
	}
	sort(edge+1,edge+1+len,cmp);
//	fo(i,1,len){
//		cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<" "<<edge[i].id<<endl;
//	}
	ll x=1;
	fo(i,1,k)x*=2;
	fo(i,0,x-1){
		fo(j,1,n+20)fa[j]=j;
		ans=min(ans,kr(i));
	//	cout<<i<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

