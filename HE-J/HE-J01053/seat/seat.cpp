#include<bits/stdc++.h> 
using namespace std;
int n,m;
int b[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>b[i];
	}
	int x=b[0];
	sort(b,b+n*m);
	int ans;
	for(int i=0;i<n*m;i++)
	{
		if(b[i]==x)
		{
			ans=n*m-i;
			break;
		}
	}
	int c=(ans+n-1)/n;
	int d=ans%n;
	if(d==0)
	{
		d=n;
	}
	cout<<c<<" "<<d;
	return 0;
}
