#include<bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int b[100],c,d,a;
	cin >> c >> d;
	for (int f = 1;f <= c * d;f++)
	{
		cin >> b[f];
	}
    a = b[1];
    for (int i = 1;i <= d;i++)
    {
    	for (int j = i+1;j <= d;j++)
    	{
    		if (b[i] < b[j])
    		{
    			int t = b[i];
    			b[i] = b[j];
    			b[j] = t;
			}
		}
	}
	int g = 1,o = 0;
	for (int y = 1;y <= c * d;y++)
	{
		if (a == b[y])
	    {
		    for (int j = 1;j <= c;j++)   
			{			
				if (y > d)
		        {
		    	    g++;
			    }
			    d += d;
		    }
		    if (g % 2 == 0)
		    {
		    	for (int u = 1;u <= c/2;u++)    
				{	
					if (y == u)
		    	    {
		    		    o = y + u - c;
				    }
				}
			}
	    } 
    }
    cout << g << " " << o;
	return 0;
} 
