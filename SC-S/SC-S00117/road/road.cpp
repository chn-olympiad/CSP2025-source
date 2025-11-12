#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,l1,l2,len,c[15],go[10015],ans;
ll d;
bool kj[10015];
vector<pair<ll,ll>>r[10015];
void solve_1(){
	for(int i=1;i<=m;i++){
		cin>>l1>>l2>>len;
		r[l1].push_back({l2,len});
		r[l2].push_back({l1,len});
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>c[i-n];
		for(int k=1;k<=n;k++){
			cin>>len;
			r[i].push_back({k,len});
			r[k].push_back({i,len});
		}
	}
	d=1;
	ll maxn=0x3f3f3f3f,d2;
	kj[1]=1;
	memset(go,0x3f,sizeof(go));
	go[1]=0;
	while(true){
		d2=-1;
		maxn=0x3f3f3f3f;
		for(auto it=r[d].begin();it!=r[d].end();it++){
			if(kj[it->first]==0){
				go[it->first]=min(go[it->first],it->second);
				if(it->second<maxn){
					maxn=it->second;
					d2=it->first;
				}
			}
		}
		kj[d2]=1;
		d=d2;
		if(d2==-1){
			break;
		}
	}
	ans=0;
	for(int i=1;i<=n;i++){
		ans+=go[i];
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	solve_1();
	return 0;
}