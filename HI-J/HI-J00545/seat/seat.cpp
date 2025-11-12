#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,a[110],b = 0,lie = 0,hang = 0,d;
	cin >> c >> r;
	d = c * r;
	for (int i = 1;i <= d;i++)
	{
		cin >> a[i];
	}
	b = a[1];
	for (int i = 1;i <= c+1;i++)
	{
		for (int j = 1;j <= r+1;j++)
		    if (a[j] < a[j+1])
		    {
			    swap(a[j],a[j+1]);
		    }
	}
	for (int i = 1;i <= d;i++)
	{
	   	if (b == a[i])
    	{
		  	if (i <= r)
     	    {
	        	cout << 1 << " " << i;
		       	break;
	   	    }
		    else
	   	    {
	   	    	if (i % c == 0)
	   	    	{
	    	        cout << i/r << " " << i/c;
		            break;
	            }
	            else
	            {
	            	cout << (i%c)+1 << " " << i/c;
				}
		    }
		}
    }
}
