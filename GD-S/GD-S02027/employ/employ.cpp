#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,c[600],ans,a[600],v[600];
string s;
void dfs(ll k){
	ll i;
	if(k==n){
		ll cnt1=0,cnt2=0;
		for(i=1;i<=n;i++){
			if(s[i-1]=='0') {
			cnt1++;
			continue;
		    }
			if(c[a[i]]>cnt1){
				cnt2++;
			}
			else cnt1++;
		}
		if(cnt2>=m) ans++;
		return;
	}
	for(i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			a[k+1]=i;
			dfs(k+1);
			v[i]=0;
		}
	}
}
int main(){
	ll i;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=n;i++) cin>>c[i];
	if(n<=18){
	dfs(0);
    }
	else{
		ll cnt=0;
		for(i=1;i<=n;i++)
		if(c[i]==0) cnt++;
		if(n-cnt<m){
			cout<<0;
			return 0;
		}
		ans=1;
		for(i=n;i>=1;i--)
		ans*=i,ans%=mod;
	}
	cout<<ans;
}

