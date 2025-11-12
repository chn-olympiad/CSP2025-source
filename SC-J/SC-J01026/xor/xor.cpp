#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll a[N],sum[N];
struct st{
	ll x,y;
}mp[N];
bool cmp(st p,st q){
	if(p.y==q.y) return (p.y-p.x+1)<(q.y-q.x+1);
	return p.y<q.y;
}
map<ll,vector<ll>> mp1;
ll n,k,ans=0,cnt=0;
ll ffnd(ll x,ll st){
	for(auto c:mp1[x]){
		if(c>=st&&c<=n){
			return c;
		}
	}
	return -1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
		cin>>a[i],sum[i]=sum[i-1]^a[i],mp1[sum[i]].push_back(i);
	for(ll i=1;i<=n;i++){
		ll fnd=ffnd(k^sum[i-1],i);
		if(fnd!=-1){
			mp[++cnt].x=i;
			mp[cnt].y=fnd;
		}
	}
	sort(mp+1,mp+cnt+1,cmp);
	ll lsy=0;
	for(ll i=1;i<=cnt;i++){
		if(mp[i].x>lsy) ans++,lsy=mp[i].y;
	}
	cout<<ans;
	return 0;
}