#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const ll mod=998244353;
ll n,a[5005],ans;
map<ll,ll>mp;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		if(i>2){
			ll cnt=0;
			for(auto j:mp){
				if(j.fi>a[i]){
					ans+=j.se;
					ans%=mod;
				}
			}
		}
		queue<pair<ll,ll> >q;
		for(auto j:mp){
			q.push({j.fi,j.se});
		}
		while(!q.empty()){
			auto t=q.front();
			q.pop();
			if(t.fi+a[i]>a[n]*2+1){
				mp[a[n]*2+1]+=t.se;
				mp[a[n]*2+1]%=mod;
			}
			else{
				mp[t.fi+a[i]]+=t.se;
				mp[t.fi+a[i]]%=mod;
			}
		}
		mp[a[i]]++;
		mp[a[i]]%=mod;
	}
	for(auto j:mp){
		if(j.fi>a[n]){
			ans+=j.se;
			ans%=mod;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
