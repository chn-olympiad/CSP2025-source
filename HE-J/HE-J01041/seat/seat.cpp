#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int c=1,r=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
    	if(a[1]<a[i])
    	{
    	    sum++;	
		}
	}
	if(sum==1)
	{
		cout<<c<<" "<<r;
	}
	else if(sum<n&&sum!=1&&r==1)
	{
		cout<<c<<" "<<sum;
	}
	else if(sum>n)
	{
		
		c=c+sum/n;
		if(c%2==0)
		{
			r=r+m-sum%n;
			cout<<c<<" "<<r;
		}
		else
		{
			r=sum%n;
			cout<<c<<" "<<r;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
