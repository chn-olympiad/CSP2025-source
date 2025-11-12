#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],sum,jiem;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2]){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
