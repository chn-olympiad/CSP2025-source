#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n ,m;
	cin >> n >> m;
	int h[100005] ;
	int ty=0;
	int c,r;
	for(int i=0;i<=n*m;i++)
	{
		for(int po=0;po<=i;po++)
		{
			cin >> h[i];
		    if(h[i]>h[i-po]&&i>0)
		    {
			    int j=h[i];
			    int k=h[i-po];
			    int h[i]=k;
			    int h[i-po]=j;
			    int j=0;
			    int k=0;
			    if(i-po==ty)
			    {
			    	int ty=i;
				}
		    }
	    }
	}
	for(int asd=0;asd<=n*m;asd++)
	{
		for(int hhhhh=1;hhhhh<=m;hhhhh++)
		{
			if(asd==ty)
		    {
		    	if()
			    int c=1;
		        int r=asd;
			    cout << c << r;
		    }
		    
		}
	}
	
	
	
	return 0;
}
