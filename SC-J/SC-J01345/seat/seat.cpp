#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	cin>>a[1];
	int b=a[1];
	for(int i = 2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	int r;
	for(int i = 1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			r=i;
		}
	}
	int l=r/(n+1)+1;
	int h=r-(l-1)*n;
	if(h%2==0)
	{
		h=n-h+1;
	}
	cout<<l<<' '<<h;
	return 0;
}