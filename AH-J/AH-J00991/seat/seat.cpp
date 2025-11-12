#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],ans=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	cin>>a[1];
	int p=a[1];
	for(int i=2;i<=k;i++)
	{
		cin>>a[i];
		if(a[i]>p)ans++;
	}
	ans++;
	if(ans%n==0)
	{
		int y=ans/n;
		if(y%2==1)cout<<y<<" "<<n;
		else cout<<y<<" "<<1;
		return 0;
	}
	int q=ans/n,r,l;
	if(q%2==1)
	{
		r=q+1;
		l=n-(ans%n)+1;
	}
	else if(q%2==0)
	{
		r=q+1;
		l=ans%n;
	}
	cout<<r<<" "<<l;
	return 0;
}
