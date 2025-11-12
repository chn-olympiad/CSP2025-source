#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+5];
	cin>>a[1];
	int c=a[1],g,p,q;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==c)
		{
			g=n*m+1-i;
		}
	}
	if(g%n==0) q=g/n;
	else q=g/n+1;
	if(g%n==0)
	{
		if(q%2==0) p=1;
		else p=n;
	}
	else
	{
		if(q%2==1) p=g%n;
		else p=n-g%n+1; 
	}
	cout<<q<<" "<<p;
	return 0;
}
