#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e3+5;
const int mod=998244353;
int a[maxn],n,ans;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int l=1;l<n;l++)
		for(int r=l+1;r<=n;r++)
			for(int i=r+1;i<=n;i++){
				if(a[i]<=a[l]+a[r]){
					int Len=l-1;
					ans=(ans%mod+((((Len+1)*Len)%mod)/2)%mod);
				}
				if(a[i]<a[l]+a[r])ans=(ans+1)%mod;
			}
	cout<<ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
	return 0;
}
