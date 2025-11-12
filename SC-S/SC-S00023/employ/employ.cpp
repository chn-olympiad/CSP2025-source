#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m,s[501],sum,cnt,ans;
string a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<i;j++){
			sum+=(ll)(a[j]);
		}
		if((s[i]>sum&&s[i]>cnt)||a[i]=='1'){
			ans++;
		}else if(s[i]<=sum){
			cnt++;
		}
	}
	cout<<ans;
	
	return 0;
}