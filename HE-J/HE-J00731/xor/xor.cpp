#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e6;
ll a[N],n,k,dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		ll num=0;
		for(int j=i;j<=n;j++){
			num=num^a[j];
			if(num==k||a[j]==k){
				dp[i]++;
				num=0;
			}
		}
		ans=max(ans,dp[i]);
		if(n-i+1<=ans){
			break;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
