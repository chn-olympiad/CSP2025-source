#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[150],x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	s=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		int c=n*m-i+1;
		if(a[i]==s)
		{
			if(c/n%2==0&&c%n==0)
			{
				x=1;
				y=c/n;
			}
			else if(c/n%2==0||c%n==0)
			{
				if(c%n==0) x=n;
				else x=c%n;
				if(c%n!=0) y=c/n+1;
				else y=c/n;
			}
			else
			{
				if(c%n==0) x=n;
				else x=n-c%n+1;
				if(c%n!=0) y=c/n+1;
				else y=c/n;
			}
			break;
		}
	}
	printf("%d %d",y,x);
	return 0;
}
