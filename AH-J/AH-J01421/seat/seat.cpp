#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,f,k,r,c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==f)
		{
			k=i;
		}
	}
	r=k%n;
	if(r==0) r=n;
	c=(k-1)/m+1;
	if(c%2==0) r=n+1-r;
	cout<<c<<' '<<r;
	return 0;
}
