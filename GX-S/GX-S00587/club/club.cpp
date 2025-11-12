#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int pp = 1;pp <= t;pp++)
	{
		int n,a[200005][5],ans = 0,z2 = 0,z3 = 0;
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= 3;j++)
			{
				cin >> a[i][j];
			}
			if (a[i][2] == 0)
				z2++;
			if (a[i][3] == 0)
				z3++;
		}
		if (n == 2)
		{
			for (int i = 1;i <= 3;i++)
			{
				for (int j = 1;j <= 3;j++)
				{
					if (i == j)
					{
						continue;
					}
					else
					ans = max(a[1][i] + a[2][j],ans);
				}
			}
			cout << ans << endl;
		}
		else if (z2 == z3 && z2 == n)
		{
			int b[200005];
			for (int i = 1;i <= 200000;i++)
			{
				b[i] = 0;
			}
			for (int i = 1;i <= n;i++)
			{
				b[i] = a[i][1]; 
			}
			sort(b + 1,b + n + 1);
			for (int i = n;i > n / 2;i--)
			{
				ans += b[i];
			}
			cout << ans << endl;
		}
		else
		{
			int x = 0,y = 0,z = 0,xl = 0,yl = 0,zl = 0;
			int qxx = 0,qxy = 0,qxz = 0;
			int qyx = 0,qyy = 0,qyz = 0;
			int qzx = 0,qzy = 0,qzz = 0;
			int pxx = 0,pxy = 0,pxz = 0;
			int pyx = 0,pyy = 0,pyz = 0;
			int pzx = 0,pzy = 0,pzz = 0;
			for (int i = 1;i <= n;i++)
			{
				if (a[i][1] + x >= a[i][1] + y && a[i][1] + x >= a[i][1] + z && qxx < n/2)
				{
					xl = a[i][1] + x;
					pxx = qxx + 1;
					pxy = qxy;
					pxz = qxz;
				}
				else if (a[i][1] + y >= a[i][1] + x && a[i][1] + y >= a[i][1] + z && qyx < n/2)
				{
					xl = a[i][1] + y;
					pxx = qyx + 1;
					pxy = qyy;
					pxz = qyz;
				}
				else if (a[i][1] + z >= a[i][1] + y && a[i][1] + z >= a[i][1] + x && qzx < n/2)
				{
					xl = a[i][1] + z;
					pxx = qzx + 1;
					pxy = qzy;
					pxz = qzz;
				}
				if (a[i][2] + x >= a[i][2] + y && a[i][2] + x >= a[i][2] + z && qxy < n/2)
				{
					yl = a[i][2] + x;
					pyx = qxx;
					pyy = qxy + 1;
					pyz = qxz;
				}
				else if (a[i][2] + y >= a[i][2] + x && a[i][2] + y >= a[i][2] + z && qyy < n/2)
				{
					yl = a[i][2] + y;
					pyx = qyx;
					pyy = qyy + 1;
					pyz = qyz;
				}
				else if (a[i][2] + z >= a[i][2] + y && a[i][2] + z >= a[i][2] + x && qzy < n/2)
				{
					yl = a[i][2] + z;
					pyx = qzx;
					pyy = qzy + 1;
					pyz = qzz;
				}
				if (a[i][3] + x >= a[i][3] + y && a[i][3] + x >= a[i][3] + z && qxz < n/2)
				{
					zl = a[i][3] + x;
					pzx = qxx;
					pzy = qxy;
					pzz = qxz + 1;
				}
				else if (a[i][3] + y >= a[i][3] + x && a[i][3] + y >= a[i][3] + z && qyz < n/2)
				{
					zl = a[i][3] + y;
					pzx = qyx;
					pzy = qyy;
					pzz = qyz + 1;
				}
				else if (a[i][3] + z >= a[i][3] + y && a[i][3] + z >= a[i][3] + x && qzz < n/2)
				{
					zl = a[i][3] + z;
					pzx = qzx;
					pzy = qzy;
					pzz = qzz + 1;
				}
				qxx=pxx;
				qxy=pxy;
				qxz=pxz;
				qyx=pyx;
				qyy=pyy;
				qyz=pyz;
				qzx=pzx;
				qzy=pzy;
				qzz=pzz;
				x=xl;
				y=yl;
				z=zl;
			}
			ans = max(x,y);
			ans = max(ans,z);
			cout << ans << endl;;
		}
		/*else
		{
			int x = 0,y = 0,z = 0,x1 = 0,y1 = 0,z1 = 0;
			for (int i = 1;i <= n;i++)
			{
				if (i <= n/2)
				{
					x1 = max(a[i][1] + x,x1);
					x1 = max(a[i][1] + y,x1);
					x1 = max(a[i][1] + z,x1);
					y1 = max(a[i][2] + x,y1);
					y1 = max(a[i][2] + z,y1);
					y1 = max(a[i][2] + y,y1);
					z1 = max(a[i][3] + x,z1);
					z1 = max(a[i][3] + y,z1);
					z1 = max(a[i][3] + z,z1);
				}
				else
				{
					x1 = max(a[i][1] + y,x1);
					x1 = max(a[i][1] + z,x1);
					y1 = max(a[i][2] + z,y1);
					y1 = max(a[i][2] + x,y1);
					z1 = max(a[i][3] + x,z1);
					z1 = max(a[i][3] + z,z1);
				}
				x = x1;
				y = y1;
				z = z1;
				//cout << x << " " << y << " " << z << endl;
			}
			ans = max(x,y);
			ans = max(ans,z);
			cout << ans << endl;
		}*/
	}
	return 0;
}
