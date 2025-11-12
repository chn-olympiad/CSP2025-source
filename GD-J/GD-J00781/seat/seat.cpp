#include <bits/stdc++.h>
using namespace std;
int n,m;
int x,y;
int p=1,l,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<n*m;i++)
	{
		cin>>y;
		if(y>x)
		{
			p++;
		}
	}
	l=(p-1)/n;
	r=p-l*n;
	cout<<l+1<<' ';
	if((l+1)&1)
	{
		cout<<r;
	}
	else
	{
		cout<<n-r+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
