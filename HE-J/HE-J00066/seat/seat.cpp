#include<bits/stdc++.h>
using namespace std;
int a[101],b[101],t,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int h=a[1];
	sort(a+1,a+n*m+1);
	int j=1;
	for(int i=n*m;i>0;i--)
	{
		b[j]=a[i];
		if(b[j]==h)
		{
			t=j;
			break;
		}
		j++;
	}
	if(t%n==0)
	{
		c=t/n;
		if(c%2==0)	r=1;
		else r=n;
	}
	else
	{
		c=t/n+1;
		if(c%2==0)	r=n-t%n+1;
		else	r=t%n;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
