#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
string a[100005],b[100005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
	}
	while(q--)
	{
		string x,y;
		int cnt = 0;
		cin >> x >> y;
		string px = x;
		int len = px.length();
		for (int i = 1;i <= n;i++)
		{
			int leni = a[i].length();
			for (int j = 0;j + leni - 1 < len;j++)
			{
				if (px.substr(j,leni) == a[i])
				{
					if (px.substr(0,j) + b[i] + px.substr(j + leni,len - (j + leni - 1)) == y)
					{
						cnt++;
					}
				}
			}
		}
		cout << cnt << endl;
	}
}
