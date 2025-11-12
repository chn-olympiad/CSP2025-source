#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+5;
const ll M=1e6+5+10*N;

ll n,m,k,c[20],a[20][N];
struct node{
	ll u,v,w;
}e[M];
struct node1{
	ll u,v,w;
}e1[M];
ll f[N],ans;

bool cmp(node s1,node s2){
	return s1.w<s2.w;
}
bool cmp1(node1 s1,node1 s2){
	return s1.w<s2.w;
}


ll find(ll x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(ll x,ll y){
	x=find(x);
	y=find(y);
	if(x!=y){
		f[x]=y;
	}
}


int main(){
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	bool flagA=1;
	for(ll j=1;j<=k;j++){
		cin>>c[j];
		if(c[j]!=0) flagA=0;
		for(ll i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	for(ll i=1;i<=n+k;i++){
		f[i]=i;
	}


	if(flagA){
		for(ll j=1;j<=k;j++){
			for(ll i=1;i<=n;i++){
				e[++m].u=n+j;
				e[m].v=i;
				e[m].w=a[j][i];
			}			
		}
	}	
	if(k==0||flagA){
		sort(e+1,e+m+1,cmp);
		for(ll i=1;i<=m;i++){
			if(find(e[i].u)!=find(e[i].v)){
				merge(e[i].u,e[i].v);
				ans+=e[i].w;
			}
		}
		cout<<ans;
		return 0;
	}

	ans=1e18;
	for(ll s=0;s<=((1<<k)-1);s++){
		for(ll i=1;i<=m;i++){
			e1[i].u=e[i].u;
			e1[i].v=e[i].v;
			e1[i].w=e[i].w;
		}
		for(ll i=1;i<=n+k;i++){
			f[i]=i;
		}

		ll tmp=s,j=1,cnt=m,res=0;
		while(tmp){
			if(tmp&1){
				res+=c[j];
				for(ll i=1;i<=n;i++){
					e1[++cnt].u=n+j;
					e1[cnt].v=i;
					e1[cnt].w=a[j][i];
				}	
			}
			tmp>>=1;
			j++;
		}
		sort(e1+1,e1+cnt+1,cmp1);
		for(ll i=1;i<=cnt;i++){
			if(find(e1[i].u)!=find(e1[i].v)){
				merge(e1[i].u,e1[i].v);
				res+=e1[i].w;
			}
		}

		ans=min(ans,res);
	}
	cout<<ans;

	return 0;
}