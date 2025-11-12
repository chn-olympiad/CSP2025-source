#include<bits/stdc++.h>
#define ll long long int
#define inc(i,l,r) for(i=l;i<=r;++i)
using namespace std;
ll a[11][10050],c[11],fa[10050],cnt,sum;
vector<pair<ll,ll> > G[10050];
struct bian{
	ll u,v,w;
}e[9900050];
bool cmp(bian a,bian b){
	return a.w<b.w;
}
ll find(ll x){
	if(x==fa[x])return x;
	return x=find(fa[x]);
}

void ku(ll x){
	ll u=e[x].u,v=e[x].v;
	
	if(find(u)!=find(v)){
		sum+=e[x].w;
		cnt++;
	}
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	
    ll i,j,g,f,h,l;
	inc(i,1,m){
		ll u,v,w;
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
		
	}
	inc(j,1,k){		
		cin>>c[j];
		inc(g,1,n)cin>>a[j][g];		
	}
	inc(f,1,n){
		inc(h,f+1,n){
		    e[i].u=f;
			e[i].v=h;
			e[i].w=1e9;
			inc(l,1,k){
			e[i].w=min(e[i].w,a[l][f]+a[h][f]);	
			}
			i++;
		}
	}
	sort(e,e+i,cmp);
	ll ii;
	inc(ii,1,n)fa[ii]=ii;
	inc(ii,1,i){
		ku(ii);
		if(cnt==n-1)break;
	}
	cout<<sum;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
