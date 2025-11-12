#include <bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;
int n;
int a[5005],b;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b+=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--){
		int b1=b;
		b1-=a[i];
		if(b1>=a[i]+1)
			ans++;
		for(int j=i-1;j>=1;j--){
			b1-=a[j];
			if(b1>=a[i]+1)
				ans++;
		}
	}
	cout<<ans%mod;
	return 0;
}
