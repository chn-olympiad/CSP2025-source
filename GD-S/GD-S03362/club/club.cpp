#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct T
{
	int a;
	int b;
	int c;
}x[100005];
int a[100005][5];
int ans;
int T;
int n;
int i1,i2,i3,i4;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	for (int zd = 1; zd <= T;zd++)
	{
		ans = 0;
		cin >> n;
		if (n <= 2)
		{
			for (int z = 1; z <= n;z++)
			{	
				cin >> x[z].a >> x[z].b >> x[z].c;
				ans = max(x[1].a+x[2].b,x[1].b+x[2].a);
				ans = max(ans,x[1].a+x[2].c);
				ans = max(ans,x[1].c+x[2].a);
				ans = max(ans,x[1].c+x[2].b);
				ans = max(ans,x[1].b+x[2].c);	
			}
		cout << ans;
		}
		if (n > 2)
		{
			for (int z = 1; z <= n;z++)
			{
				for (int i = 1; i <= 3;i++)
				{
					cin >> a[z][i];
				}
			}
			
			for ( i1 = 1; i1 <= n;i1++)
			{
				for (i2 = 1 ; i2 <= n;i2++)
				{
					for (i3 = 1 ; i3 <= n;i3++)
					{
						for (i4 = 1 ; i4 <= n;i4++)
						{
							if (i1 == i2)
							{
								if (i1 != i3)
								{		
									if (i1 != i4)
									{
										ans = max(ans,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]);
							
									}
								}
							}
							if (i2 == i3)
							{
								if (i2 != i4)
								{		
									if (i2 != i1)
									{
										ans = max(ans,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]);
						
									}
								}
							}
							if (i3 == i4)
							{
								if (i3 != i1)
								{		
									if (i3 != i2)
									{
										ans = max(ans,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]);
									
									}
								}
							}
							if (i4 == i1)
							{
								if (i4 != i2)
								{		
									if (i4 != i3)
									{
										ans = max(ans,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]);
								
									}
								}
							}
							if (i1 == i3)
							{
								if (i1 != i2)
								{		
									if (i1 != i4)
									{
										ans = max(ans,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]);
									
									}
								}
							}
							if (i2 == i4)
							{
								if (i2 != i3)
								{		
									if (i2 != i1)
									{
										ans = max(ans,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]);
									}
								}
							}
						}
					}
				}
			}
			cout << ans;
		}
	}
	return 0;
}
