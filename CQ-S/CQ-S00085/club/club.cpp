#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
ll x[3];
ll a[100001][3];
ll s[100001];
bool mxs(ll i,ll j) {
	if(j==0)
		return a[i][0]>=max(a[i][1],a[i][2]);
	if(j==1)
		return a[i][1]>=max(a[i][0],a[i][2]);
	return a[i][2]>=max(a[i][0],a[i][1]); 
}
int sed(ll i,ll j) {
	if(j==0) {
		if(a[i][1]>=a[i][2])
			return 1;
		return 2;
	}
	if(j==1) {
		if(a[i][2]>=a[i][0])
			return 2;
		return 0;
	}
	if(a[i][1]>=a[i][0])
		return 1;
	return 0;
}
void sol() {
	memset(a,0,sizeof a);
	memset(x,0,sizeof x);
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<3;j++)
			cin>>a[i][j];
		if(mxs(i,0))
			x[0]++;
		else {
			if(mxs(i,1))
				x[1]++;
			else
				x[2]++;
		}
			ll mx=0;
			for(int j=0;j<3;j++)
				mx=max(mx,a[i][j]);
			ans+=mx;
	}
	if(x[0]<=n/2&&x[1]<=n/2&&x[2]<=n/2)
		cout<<ans<<'\n';
	else {
		for(int j=0;j<3;j++) {
			if(x[j]>n/2) {
				ll c=0;
				for(int i=1;i<=n;i++) 
					if(mxs(i,j)) 
						s[++c]=a[i][sed(i,j)]-a[i][j];
				sort(s+1,s+1+c);
				for(int r=c;r>=c-(x[j]-n/2)+1;r--)
					ans+=s[r];
				cout<<ans<<'\n';
			}
		} 
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
		sol();
    return 0;
}

