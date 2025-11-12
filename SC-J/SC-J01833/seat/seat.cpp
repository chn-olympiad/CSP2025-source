#include<bits/stdc++.h>
using namespace std;
int a[200];
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
	int r=a[1],e;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			e=n*m-i+1;
		}
	}
	cout<<(e-1)/n+1<<" ";
	if(((e-1)/n+1)%2==0)
	{
		cout<<n-(e-1)%n;
	}
	else
	{
		cout<<(e-1)%n+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}