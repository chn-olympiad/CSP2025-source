#include <iostream>
#include <algorithm>
using namespace std;
int mugun[50005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,maxn,sum = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> mugun[i];
		maxn = max(maxn,mugun[i]);
		sum += mugun[i];
	}
	if (n == 3)
	{
		if (sum > 2 * maxn) cout << 1;
		else cout << 0;
	}
	else
	{
		cout << n - 2;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
