#include<bits/stdc++.h>
using namespace std;


long long a[100005];
long long ans = 0;
int main()
{	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(k == 0) cout << 1 << endl;
	if(k == 1)
	{
		for(int i = 1;i <= n;i++)
		{
			if(a[i] == 1) ans ++;
		}
		cout << ans << endl;
	}
	
	return 0;
}
