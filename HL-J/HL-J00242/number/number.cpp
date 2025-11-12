#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	string a;
	cin >> a;
	int b[100005];
	for (int i=1;i<=size(a);i++)
	{
		if (a[i]>=1 && a[i]<=9)
		{
			for (int j=1;j<=size(a);j++)
			{
				cin >> b[i];
				n++;
			}
		}
	}
	sort(b[1],b[n+1]);
	for (int i=1;i<=n;i++)
	{
		cout << b[i];
	}
	
	return 0;
}

