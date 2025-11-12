#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int main()
{
	//freopen ("club.in" , "l" , stdin);
	//freopen ("club.out" , "w" , stdout);
	int t;
	cin >> t;
	for (int i=1;i<=t;i++)
	{  
	    int n;
	    cin >> n;
	    int a[n+1][4];
	    int b[n+1];
	    b[0] = 0;
	    for (int i=1;i<=n;i++)
	    {
	    	cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		int m = 0;
		int k[3];
		k[1] = 0;
		k[2] = 0;
		k[3] = 0; 
		for (int i=1;i<=n;i++)
	    {
	    	if (k[1] <= 0.5*n)
	    	    if (k[2] <= 0.5*n)
	    	        if (k[3] <= 0.5*n)
	    	        {
					    b[i] = b[i-1] + max(a[i][1] , max(a[i][2] , a[i][3]));
					    m = max(b[i],m);
					    if (a[i][3] > a[i][1] || a[i][3] > a[i][2])
					    {
					    	k[3]++;
						}
						else if (a[i][2] > a[i][1] || a[i][2] > a[i][3])
					    {
					    	k[2]++;
						}
						else
						{
							k[1]++;
						}
					}
					else
					{
						b[i] = b[i-1] + max(a[i][1],a[i][2]);
					    m = max(b[i],m);
						if (a[i][2] > a[i][1] || a[i][2] > a[i][3])
					    {
					    	k[2]++;
						}
						else
						{
							k[1]++;
						}
					}
				else
				{
					b[i] = b[i-1] + max(a[i][1],a[i][3]);
					m = max(b[i],m);
					if (a[i][3] > a[i][1] || a[i][3] > a[i][2])
					{
					    k[3]++;
					}
					else
					{
						k[1]++;
					}
				}
			else
			{
				b[i] = b[i-1] + max(a[i][2],a[i][3]);
				m = max(b[i],m);
				if (a[i][3] > a[i][1] || a[i][3] > a[i][2])
				{
					k[3]++;
				}
				else
				{
					k[2]++;
				}
			}
		}
		cout << m << endl;
    }
}
