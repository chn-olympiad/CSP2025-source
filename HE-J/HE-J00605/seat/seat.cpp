#include <bits/stdc++.h>
using namespace std;
int a[5005][5005], b[1000005], n, m;
bool cmp(int x, int y)
{
	return x < y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> b[i];
	}
	int f = b[1];
	int l = n*m;
	int k = 1;
	sort(b+1,b+l+1,cmp);
	for (int i = 1;i <= m;i++)
	{
		if (i % 2 == 1)
		{
		    for(int j = 1;j <= n;j++)
	   	    {
			    a[i][j] = b[k]; 
			    k++;
		    } 
		}
		else
		{
			for (int j = n;j >= 1;j--)
			{
				a[i][j] = b[k];
				k++;
			}
		}
	}
	for (int i = 1;i <= m;i++)
	{
		if (i % 2 == 1)
		{
		    for(int j = 1;j <= n;j++)
		    {
		    	if (a[i][j] == f)
		    	{
		    		cout << i << " " << j;
		    		return 0;
		    	}
		    }  
		}
		else
		{
			for(int j = n;j >= 1;j--)
		    {
			    if (a[i][j] == f)
		    	{
			    	cout << i << " " << j;
			    	return 0;
			    }
		    } 
		}
	}
    return 0;	
} 
