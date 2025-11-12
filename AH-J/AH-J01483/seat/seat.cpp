#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int zw=a[1];
	sort(a+1,a+1+n*m);
	int pos;
	for(int i=1;i<=n*m/2;i++)
		swap(a[i],a[n*m-i+1]);
	for(int i=1;i<=n*m;i++)
		if(a[i]==zw)pos=i;
	int c,r;
	if(pos%n==0)
	{
		pos/=n;
		if(pos%2==1)c=pos,r=n;
		else c=pos,r=1;
	}
	else
	{
		c=pos/n+1;
		if(c%2==1)r=pos%n;
		else r=n-pos%n+1;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
