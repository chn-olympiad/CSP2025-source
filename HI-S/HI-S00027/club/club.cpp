#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],ni,yy,yu[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	int ans[100005],b[100005],ch[100005],xna[100005];
	for (int x = 1;x <= t;x++)
	{
		cin >> n;
		ni -= ni;
		ni += n/2;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= 3;j++)
			{
				cin >> a[i];
				if (j == 1)
				{
					ans[i] += a[i];
				}
				else if (j == 2)
				{
					b[i] += a[i];
				}
				else if (j == 3)
				{
					ch[i] += a[i];
				}
				xna[i] += max(xna[i],a[i]);
			}
		}
		for (int i = 1;i <= n;i++)
		{
   			yy += max(ans[i],max(b[i],ch[i]));
		}
		yu[x] += yy;
		yy -= yy;
	}
	for (int x = 1;x <= t;x++)
	{
		cout << yu[x] << endl;
	}
	return 0;
}

