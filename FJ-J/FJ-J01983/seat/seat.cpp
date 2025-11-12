#include<iostream>
using namespace std;
int a[101];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int post=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[1])
			post++;
	}
	int c,r;
	if(post%n == 0) c=post/n;
	else c=post/n+1;
	if(c%2 == 0)
	{
		r=n-post%n+1;
		if(r == n+1) r=1;
	}
	else
	{
		r=post%n;
		if(r == 0) r=n;
	}
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
