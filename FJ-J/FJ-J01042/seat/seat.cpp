#include<bits/stdc++.h>
using namespace std;
	int a[150];
	int xh[150];
int n,m,wz,c=1,r=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		xh[i]=i;
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[j]>=a[i])
			{
				swap(a[j],a[i]);
				swap(xh[j],xh[i]);
			}
		}
	}
    for(int i=1;i<=n*m;i++)
    {
    	if(xh[i]==1)
    	{
    		wz=i;
    		cout<<c<<" "<<r;
    		return 0;
		}
        else if(r!=n&&c%2==1)
        {
        	r++;
		}
		 else if(r!=1&&c%2==0)
        {
        	r--;
		}
		 else if(c%2==1&&r==n)
        {
        	c++;
		}
		 else if(c%2==0&&r==1)
        {
        	c++;
		}
	}
}
