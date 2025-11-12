#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;

struct node{
	ll cost;
	ll ccnt;
	ll i;
	vector<ll> cnd;
};

ll n,m,k,mx1,mx2,mx3;
ll mnc,mni,mn,man[N];
map<ll,node> conn;
vector<ll> mcnd,ncnd;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		conn[u].cost+=w;
		conn[u].i=i;
		conn[u].ccnt++;
		conn[u].cnd.push_back(v);
	}
	for(auto i=conn.begin();i!=conn.end();i++){
		if(i->second.ccnt>mx1){
			mx1=i->second.ccnt;
			mx2=i->second.cost;
			mx3=i->second.i;
			mcnd=i->second.cnd; 
		}
	}
	for(int i=1;i<=n;i++){
		bool f=false;
		for(ll j=1;j<=mcnd.size();j++){
			if(mcnd[j]==i) f=true;
		}
		if(!f){
			ncnd.push_back(i);
		}
	} 
	for(int i=1;i<=k;i++){
		ll x,an[N]; cin>>x;
		for(ll j=1;j<=n;j++) cin>>an[j];
		if(x<mn){
			mn=x;
			mni=i;
			man=an;
		}
	}
	for(int i=0;i<ncnd.size();i++){
		mx2+=man[ncnd[i]];
	}
	cout<<mx2;
	return 0;
} 
