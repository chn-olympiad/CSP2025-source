#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
int f,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	f=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==f)
		{
			x=i/n;
			if(i%n!=0) x++;
			if(x%2==1)
			{
				if(i%n==0) y=n;
				else y=i%n;
			}
			else
			{
				if(i%n==0) y=1;
				else y=n-(i%n)+1;
			}
			break;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
