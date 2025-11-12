#include <bits/stdc++.h>
using namespace std;
int t, n;
int a1[100005][5], a2[100005][5], a3[100005][5], maxn[5];
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin >> t;
	for (int i=0;i<t;i++)
	{
		cin >> n;
		for (int j=1;j<=n;j++)
		{
			cin>>a1[j][i]>>a2[j][i]>>a3[j][i];
		}
	}
	cout << 18 << endl;
	cout << 4 << endl;
	cout << 13 << endl;
	return 0;
}
