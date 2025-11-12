#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b; 
}
long long n,m,a[100010],s=0,x=0,y=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i]; 
	}
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(s==a[i])
		{
			if(i%n==0)
			{
				x=i/n;
			} 
			if(i%n!=0)
			{
				x=1+i/n;
			}
			if(x%2==1)
			{
				y=i-n*(x-1);
			}
			if(x%2==0)
			{
				y=i-n*(x-1);
				y=n+1-y;
			}
			printf("%lld",x);
			cout<<" ";
			printf("%lld",y);
		} 
	}
	
	return 0;
} 
