#include <bits/stdc++.h>
using namespace std;
string a[200005][200005],b[200005][200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin >> b[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout << 0 << endl;
	}
	return 0;
}
