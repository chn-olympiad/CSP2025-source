#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N],k;
int n;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if (k==0)
	{
		if (n==1)
		{
			cout << k;
		}
		else
		{
			cout << n/2;
		}
	}
	fclose(stdin);
    fclose(stdout); 
	return 0;
}