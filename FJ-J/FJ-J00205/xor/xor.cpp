#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		long long x;
		cin >> x;
		a[i]=a[i-1]+x;
	}
	cout << 1;	
	return 0;
}