//GZ-S00236 贵阳市第三中学 李盱盈 
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pll pair<ll,ll>
ll n,answ=0;
vector<vector<ll> >a;
void dfs(ll k,ll x,ll y,ll z,ll ans){
	if(k==n+1){
		answ=max(ans,answ);
		return;
	}
	if(x<n/2)dfs(k+1,x+1,y,z,ans+a[k][1]);
	if(y<n/2)dfs(k+1,x,y+1,z,ans+a[k][2]);
	if(z<n/2)dfs(k+1,x,y,z+1,ans+a[k][3]);
}
void Charlie(){
	cin>>n;
	a.assign(n+1,vector<ll>(4,0));
	if(n<=10){
		for(ll i=1;i<=n;i++)for(ll j=1;j<=3;j++)cin>>a[i][j];
		dfs(1,0,0,0,0);
		cout<<answ<<endl;
	}
	vector<pll>ve;ll ans=0,bo=1;
	ll b[4]={0,0,0,0};
	for(ll i=1;i<=n;i++)for(ll j=1;j<=3;j++)cin>>a[i][j];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=3;j++)ve.push_back({a[i][j],j});
		sort(ve.begin(),ve.end(),greater<pll>());
		for(ll j=0;j<3;j++)
			if(b[ve[j].second]+1<=n/2){
				b[ve[j].second]++;
				ans+=ve[j].first;
				break;
			}
		ve.clear();
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--)Charlie(),answ=0;
	return 0;
}/*
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
