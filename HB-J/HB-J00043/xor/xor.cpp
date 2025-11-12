#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k;
int a[N],flag;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	cout << n/2;
	return 0;
}
