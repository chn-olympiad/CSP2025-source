#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=n-m+2;i<=n;i++){
		ans=ans*i%998244353;
	}
	printf("%lld",ans);
	return 0;
}

