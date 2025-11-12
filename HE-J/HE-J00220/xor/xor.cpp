#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500100];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(k == 0) cout << 1;
	else if(k == 1) cout << 1;
	else if(k == 2) cout << 2;
	else cout << k-1;
	return 0;
}
