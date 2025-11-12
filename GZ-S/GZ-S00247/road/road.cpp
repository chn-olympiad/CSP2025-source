//GZ-S00247 观山湖中学 李鸿哲
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ls i<<1
#define rs (i<<1)|1
const ll N=1E4+10;
ll n,m,k,dis[N][N],u,v,w,c,a[N],sum,ans,cnt,f[N];
struct node{
	ll u,v,w;
	bool operator < (const node &a) const{
	    return w<a.w;
	}
}l[N*1000];
ll find(ll x){
	if(!f[x])return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++){
    	for(ll j=1;j<=n;j++){
    		dis[i][j]=1000000000000;
		}
	}
    for(ll i=1;i<=m;i++){
    	cin>>u>>v>>w;
    	if(!k)l[++cnt]={u,v,w};
    	dis[min(u,v)][max(u,v)]=min(w,dis[min(u,v)][max(u,v)]);
	}
	for(ll i=1;i<=k;i++){
		cin>>c;
		ans+=c;
		for(ll j=1;j<=n;j++){
			cin>>a[j];
			sum+=a[j];
			for(ll h=1;h<j;h++){
				dis[h][j]=min(dis[h][j],a[j]+a[h]);
			}
		}
		if(!sum){cout<<"0\n";return 0;}
	}
	if(!k){
		sort(l+1,l+cnt+1);
	    for(ll i=1;i<=cnt;i++){
		    u=l[i].u;v=l[i].v;w=l[i].w;
		    u=find(u);v=find(v);
		    if(u==v)continue;
		    ans+=w;
		    u=v;
	    }
	    cout<<ans<<endl;
	    return 0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++)if(dis[i][j]!=1000000000000){
			l[++cnt]={i,j,dis[i][j]};
		}
	}
	sort(l+1,l+cnt+1);
	for(ll i=1;i<=cnt;i++){
		u=l[i].u;v=l[i].v;w=l[i].w;
		u=find(u);v=find(v);
		if(u==v)continue;
		ans+=w;
		u=v;
	}
	cout<<ans<<endl;
	return 0;
}

