#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,c,r,q=1,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			sum++;
		}
	}
	c=(sum+1)/n+1;
	int b=(sum+1)%n;
	if(b==0)
	{
		c--;
		q=0;
	}
	if(c%2==0)
	{
	    r=b;	
	}else{
		r=n-b+q;
	}
	cout<<c<<" "<<r<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
