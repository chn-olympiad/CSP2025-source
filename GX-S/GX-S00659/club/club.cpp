#include <iostream>
#include <cstdio>
using namespace std;
long long n,t,a[9999][9999],z,x;
int main()
{
		freopen ("club.in","r",stdin);
		freopen ("club.out","w",stdout);
		cin >> t;
		for (int y=1;y<=t;y++)
		{
				long long sum=0;
				cin >> n;
				for (int i=1;i<=n;i++)
					for (int j=1;j<=3;j++)
						cin >> a[i][j];
				for (int j=1;j<=3;j++)
				{
						x=n/2;
						while (x--)
						{
								long long ans=0;
								for (int i=1;i<=n;i++)
									if (ans<a[i][j])
									{
										if (a[i][j+1]<a[i][j]&&a[i][j+2]<a[i][j])
											if (a[i][j+1]-a[i][j]<a[i+1][j+1]-a[i+1][j])
											{
													z=i;
													ans=a[i][j];
											}
										if (a[i][j+1]==a[i][j]||a[i][j+2]==a[i][j])	
											if (a[i][j+1]-a[i][j]<a[i+1][j+1]-a[i+1][j])
												{
														z=i;
														ans=a[i][j];
												}
									}
								sum+=ans;
								a[z][j]=0;
								a[z][j+1]=0;
								a[z][j+2]=0;
						}
				}
				cout << sum << endl;
		}
		return 0;
}
