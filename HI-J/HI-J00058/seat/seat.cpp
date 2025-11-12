#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=0,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int l=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==l)
		{
			continue;
		}
		else
		{
			x++;
		}
	}
	r=x%m;
	if(x>n)
	{
		c=x/n+1;
		r=x%m+1;
	}
	else
	{
		c=1;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

