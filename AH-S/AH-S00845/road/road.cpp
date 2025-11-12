#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+25,M=2e6+25,maxN=1e4+25;
struct node{
	ll u,v,w;
	bool operator < (const node& abc) const{
		return w<abc.w;
	}
}a[M],b[N];
ll n,m,k,siz;
ll fa[N],f[N],f2[N];
ll find(ll x){
	//cout<<x<<' '<<fa[x]<<'\n';
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
ll maxf;
void Union(ll x,ll y){
	x=find(x),y=find(y);
	if(f[x]<f[y])swap(x,y);
	fa[y]=x;
	f[x]+=f[y];
	f2[x]+=f2[y];
	maxf=max(maxf,f2[x]);
}
bool isvis(){
	return maxf==n;
}
ll krus(){
	sort(b+1,b+siz+1);
	for(ll id=1;id<=n+k;id++)fa[id]=id,f[id]=1;
	for(ll id=1;id<=n;id++)f2[id]=1;
	ll i=1,j=1,len=0,x,y,ans=0;
	if(siz==0)b[++siz]={1,2,N*M};
	while(i<=m&&j<=siz){
		if(a[i].w<b[j].w){
			x=find(a[i].u),y=find(a[i].v);
			if(x==y){i++;continue;}
			ans+=a[i].w;
			Union(x,y);
			len++;
			i++;
		}
		else{
			//cout<<b[j].u<<' '<<b[j].v<<' '<<b[j].w<<'\n';
			x=find(b[j].u),y=find(b[j].v);
			if(x==y){j++;continue;}
			ans+=b[j].w;
			Union(x,y);
			len++;
			j++;
		}
		//cout<<"ok\n";
		if(len>=n-1)
			if(isvis())return ans;
	}
	return -1;
}
ll e[15][maxN];
void solve1(){
	ll i,j,w,ans=1e18;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1);
	//for(ll we=1;we<=m;we++)cout<<a[we].w<<' ';
	//cout<<"ok!\n";
	for(i=1;i<=k;i++)
		for(j=0;j<=n;j++)cin>>e[i][j];
	for(ll s=0,ker=(1<<k)-1;s<=ker;s++){
		w=s;i=1;siz=0;
		while(w){
			if(w&1)for(j=1;j<=n;j++)b[++siz]={i+n,j,e[i][j]};
			w=w>>1;
			i++;
		}
		maxf=1;
		ll x=krus();
		//if(s==0)cout<<x<<'\n';
		ans=min(ans,x);
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve1();
	return 0;
}
