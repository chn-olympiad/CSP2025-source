#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+25;
pair<ll,ll> a[N],b[5];
vector<pair<ll,ll> > v[5];
void solve(){
	ll n,i,ans=0;
	cin>>n;
	for(i=1;i<=3;i++)v[i].clear();
	for(i=1;i<=n;i++){
		for(ll j=1;j<=3;j++)cin>>b[j].first,b[j].second=j;
		sort(b+1,b+4);
		a[i].first=b[3].first-b[2].first,a[i].second=b[3].first;
		v[b[3].second].push_back(a[i]);
		ans+=b[3].first;
	}
	ll idx=-1,siz=0,half=n/2;
	for(i=1;i<=3;i++){
		ll w=v[i].size();
		if(w>siz)siz=w,idx=i;
	}
	sort(v[idx].begin(),v[idx].end());//cha cong xiao dao da
	i=0;
	while(siz>half){
		ans-=v[idx][i].first;
		i++,siz--;
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	while(n--)solve();
	return 0;
}
