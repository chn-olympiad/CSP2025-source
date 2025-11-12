#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int k,n,m;
int a[N];
int c;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		c++;
		if(a[i]==k)
		{
			k=c;
			break;
		}
	}
	c=ceil(k*1.0/n);
	if(c%2!=0)
	{
		cout<<c<<' '<<k-(c-1)*n;
	}
	else
	{
		cout<<c<<' '<<n-(k-(c-1)*n)+1;
	}
    return 0;
}
