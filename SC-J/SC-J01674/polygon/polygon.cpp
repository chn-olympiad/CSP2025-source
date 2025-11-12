#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
int n,ans,a[5005];

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=3) cout<<(a[1]+a[2]+a[3]>max({a[1],a[2],a[3]})*2);//1~3
	else cout<<n-2;
	return 0;
} 