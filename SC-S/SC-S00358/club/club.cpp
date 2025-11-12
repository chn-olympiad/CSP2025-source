#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll T,n;
struct node{
	ll id;
	ll x[4];
};
node p[N];
ll vis[N];
vector<node>cho[4];
ll getans(){
	ll bid=0;
	ll res=0;
	for(ll i=1;i<=3;i++){
		for(node j:cho[i])res+=j.x[i];
	}
	for(ll i=1;i<=3;i++)if((ll)cho[i].size()>n/2)bid=i;
	if(bid==0)return res;
	vector<ll>cg;
	for(node i:cho[bid]){
		ll mx=-0x3f3f3f3f;
		for(ll j=1;j<=3;j++){
			if(j!=bid)mx=max(mx,i.x[j]-i.x[bid]);
		}
		
		cg.push_back(mx);
	}
	sort(cg.begin(),cg.end());
	ll js=cho[bid].size(),len=cg.size();
	for(ll i=len-1;i>=0;i--){
		res+=cg[i];
		js--;
		if(js<=n/2)break;
	}
	return res;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=3;i++)cho[i].clear();
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				cin>>p[i].x[j];
				p[i].id=i;
			}
			if(p[i].x[1]>=p[i].x[2]&&p[i].x[1]>=p[i].x[3])cho[1].push_back(p[i]);
			else if(p[i].x[2]>=p[i].x[1]&&p[i].x[2]>=p[i].x[3])cho[2].push_back(p[i]);
			else cho[3].push_back(p[i]);
		}
		cout<<getans()<<'\n';
	}
	return 0;
}