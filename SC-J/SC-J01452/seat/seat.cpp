#include<bits/stdc++.h>
using namespace std;
bool s(int a,int b)
{
	return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,o=0,d;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		d=a[0];
	}
	sort(a,a+n*m,s);
	for(int i=0;i<m;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<n;j++)
	        {	
		        if(a[o]==d)
		        {
		        	cout<<i+1<<" "<<j+1;
		        	return 0;
				}
		        o++;

	        }
		}
		else
		for(int j=n-1;j>=0;j--)
	    {
	    	if(a[o]==d)
		    {
		        cout<<i+1<<" "<<j+1;
		        return 0;
			}
		    o++;
	    }
	}
	return 0;
} 