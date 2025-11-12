#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,t;
int a[105];
bool cmd(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmd);  
	for(int j=1;j<=n*m;j++)
	{
		if(a[j]==t)
		{
			if(j>n)
			{
				if(j%n!=0)
				{
					c=(j/n)+1;
					if(c%2==0)
					{
						r=n-(j%n)+1;
					}
					else
					{
						r=j%n;
					}
				}
				if(j%n==0)
				{
					c=j/n;
					if(c%2==0)
					{
						r=1;
					}
					else
					{
						r=n;
					}
				}
			}	
			if(j<=n)
			{
				c=1;
				r=j; 
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
