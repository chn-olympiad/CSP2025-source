#include <bits/stdc++.h>
using namespace std;
int k,n,a[10005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for (int i = 1;i<=n;i++){
		if (a[i]==k) ans++;
		if (a[i]^a[i+1]^a[i+2]==k&&
		(a[i]+a[i+1]+a[i+2])/2==k) ans++;
		if (a[i]==k&&i==n) ans++;
	}
	cout << ans;
}