#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],f[100005][4],s[100005],c[100005],num[10],b,h;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int sum = 0; 
		for (int i = 1; i <= n; i++)
		{
			int max=-1;
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			for (int j = 1; j <= 3; j++)
			{
				if (a[i][j] > max)
				{
					max = a[i][j];
					b = j;
				}
			}
			f[i][b] = a[i][b];
			sum += f[i][b];
			num[b]+=1;
			if (b == 1)
			{
				if (a[i][2] >= a[i][3])
				{
					s[i] = a[i][2];
				}
				else
				{
					s[i] = a[i][3];
				}
			}
			else if (b == 2)
			{
				if (a[i][1] >= a[i][3])
				{
					s[i] =  a[i][1];
				}
				else
				{
					s[i] = a[i][3];
				}
			}
			else
			{
				if (a[i][1] >= a[i][2])
				{
					s[i] =  a[i][1];
				}
				else
				{
					s[i] = a[i][2];
				}
			}
	    }
	    h = 0;
	    for (int i = 1; i <= 3; i++)
	    {
	    	if (num[i] > n/2)
	    	{
	    		h = i;
			}
		}
		if (num[1] <= n/2 && num[2] <= n/2 && num[3] <= n/2)
		{
			cout << sum << endl;  
			for (int i = 0; i <= n+1; i++)
		    {
		    	for (int j = 0; j < 4; j++)
			    {
				    a[i][j]=0,f[i][j]=0;
			    }
		    }
		    for (int i = 1; i <= n; i++)
		    {
			    s[i] = 0,c[i] = 0;
		    }
		    for (int i = 0; i <= 4; i++)
		    {
		    	num[i] = 0;
		    }
			continue;                    
		}
		int js=1;
		for (int i = 1; i <= n; i++)
		{
			if (f[i][h] > 0)
			{
				c[js] = f[i][h] - s[i];
				js++;
			}
		} 
		sort(c+1,c+js);
		for (int i = 1; i <= num[h]-n/2; i++)
		{
			sum -= c[i];
		}
		cout << sum << endl;
		for (int i = 0; i <= n+1; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				a[i][j]=0,f[i][j]=0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			s[i] = 0,c[i] = 0;
		}
		for (int i = 0; i <= 4; i++)
		{
			num[i] = 0;
		}
	}
	return 0;
}
