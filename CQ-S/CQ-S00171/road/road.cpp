#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,arr[15][10005],tot=0,ans=LONG_LONG_MAX,fa[10015],js[15];
struct node{
	ll u,v,w;
	
}edge[1100005],edge2[1100005],edge3[100005];
bool cmp(node a,node b){
	return a.w<b.w; 
}
//ll aaaa=0;
ll find(ll x){
	//aaaa++;
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
	
	
}

ll kruskal(ll x){
	ll anss=0;
	x--;
	ll dq=1,dq2=1;
	while((x--)!=0){
		if(dq2<=tot&&edge3[dq2].w<=edge2[dq].w){
		
			if(find(edge3[dq2].u)==find(edge3[dq2].v)){
				x++;
				dq2++;
				continue;
			}
		
			fa[fa[edge3[dq2].u]]=fa[fa[edge3[dq2].v]];
			anss+=edge3[dq2].w;
			dq2++;
		}
		else{
			
			if(find(edge2[dq].u)==find(edge2[dq].v)){
				x++;
				//cout<<dq<<'\n';
				dq++;
				continue;
			}
			//cout<<dq<<'\n';
		
			fa[fa[edge2[dq].u]]=fa[fa[edge2[dq].v]];
			anss+=edge2[dq].w;
			dq++;
		}
		
	}
	
	//cout<<"owl";
	//cout<<anss<<'\n';
	return anss;
	
}
signed main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;++i){
		ll a,b,c;
		cin>>a>>b>>c;
		edge2[i]={a,b,c};
	}
	for(ll i=1;i<=k;++i){
		cin>>js[i];
		for(ll j=1;j<=n;++j){
			cin>>arr[i][j];
			
		}
	}
	for(ll j=1;j<=n+k;++j){
		fa[j]=j;
	}
	sort(edge2+1,edge2+m+1,cmp);
	
	ans=min(ans,kruskal(n));
	for(ll i=1;i<=(1<<(k))-1;++i){
		//cout<<i;
		
		tot=0;
		
		ll zs=n,hf=0;
		for(ll j=1;j<=n+k;++j){
			fa[j]=j;
		}
		for(ll j=1;j<=k;++j){
			//cout<<i<<'\n';
			if((i&(1<<(j-1)))){
				hf+=js[j];
				zs++;
				for(ll aaa=1;aaa<=n;++aaa){
					edge3[++tot]={n+j,aaa,arr[j][aaa]};
					
				}
			}
		}
		sort(edge3+1,edge3+tot+1,cmp);
		ans=min(ans,kruskal(zs)+hf);
		//cout<<hf<<' '<<kruskal(zs)<<'\n';
		
	}
	cout<<ans;
	
	
	return 0;

}

