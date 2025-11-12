#include <bits/stdc+.h>
using namespace std;
int a[5005], n, k, cnt;

int main()
{
	freopen("rox.in","r",stdin);
	freopen("rox.out","w",stdout);
	cin >> n >> k;
	for (int i =1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i]==0)
		{
			cnt++;
		}
	}
	cout << cnt;
    return 0;	
} 
