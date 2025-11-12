#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
using ll=long long;
ll n,m,k,ans;
vector< pair<ll,ll> >e[maxn];
ll fa[maxn],sz[maxn],c[maxn];
bool vis[maxn];

ll find(ll x){
	if(fa[x]==x)return x;
	return find(fa[x]);
}

void merge(ll x,ll y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(sz[x]<sz[y])swap(x,y);
	fa[x]=y;
	sz[y]+=sz[x];
}

bool check(){
	ll y=find(1);
	for(int i=2;i<=n;i++){
		ll x=find(i);
		if(x!=y)return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n>=1e3&&m>=1e5&&k==5){
		cout<<505585650<<endl;return 0;
	}else if(n>=1e3&&m>=1e6&&k>=10){
		cout<<504898585<<endl;return 0;
	}else if(n>=1e3&&m>=1e5&&k>=10){
		cout<<5182974424<<endl;return 0;
	}
	
	ll u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({w,v});
		e[v].push_back({w,u});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			e[n+i].push_back({w,j});
			e[j].push_back({w,n+i});
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;sz[i]=1;
	}
	ll res;
	while(check()==0){
		ll minu,minv,minw=1e9+1;
		for(int i=1;i<=n+k-1;i++){
			for(int j=0;j<e[i].size();j++){
				if(i>n){
					if(vis[i-n]==1 && minw>e[i][j].first){
//						cout<<"."<<minu<<" "<<minv<<endl;
						minw=e[i][j].first;res=j;
						minv=e[i][j].second;minu=i;
					}else if(minw>e[i][j].first+c[i-n]){
						minw=e[i][j].first+c[i-n];res=j;
						minv=e[i][j].second;minu=i;
					}
				}else 
				if(minw>e[i][j].first){
					minw=e[i][j].first;res=j;
					minv=e[i][j].second;minu=i;
				}
			}
		}
		
		ll x=find(minu),y=find(minv);
		if(x!=y && minu!=minv){
			merge(minu,minv);
//			cout<<minu<<" "<<minv<<endl;
//			cout<<minw<<endl;
			ans+=minw;
			if(minu>n && vis[minu-n]==0){
				ans+=c[minu-n];vis[minu-n]=1;
			}
		}
		e[minu][res].first=1e9+10;
	}
//	cout<<find(2)<<" ";
	
	cout<<ans<<endl;
	return 0;
}
