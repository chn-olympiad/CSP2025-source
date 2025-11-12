#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int s[n][m];
	for (int i = 0;i < m*n;i++)
	{
		cin >> a[i];
	}
	int r = a[0];
	for (int i = 1;i < m*n;i++)	
	{
		for (int j = 0;j < m*n-i;j++)
	    {
			    
            if (a[j] < a[j+1])
		    {
			    int t = 0;
		        t = a[j];
			    a[j] = a[j+1];
			    a[j+1] = t;
	        }
	    }
    }
    
	for (int j = 0;j < m;j++)    
	{
		if (j % 2 == 1)
		{
			for (int i = n - 1;i >= 0;i--)
			{
				s[i][j] = a[j];
			}
		}
		else
		{
		    for (int i = 0;i < n;i++)
	        {
	            s[i][j] = a[i];	
	        }
	    }
    }
    
    for (int i = 0;i < n;i++)
    {
    	for (int j = 0;j < m;i++)
    	{
    		if (s[i][j] == r)
    		{
    			cout << j+1 << ' ' << i+1;
    			break;
			}
		}
	}
	return 0;
}

