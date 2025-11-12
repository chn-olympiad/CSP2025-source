#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[111],n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+n*m+1);
	int l=1,r=1,o=1;
	for(int i=n*m;i>=1;i--)
	{
		if(s==a[i])
		{
			cout<<l<<' '<<r;
			return 0;
		}
		r+=o;
		if(r>n)
		{
			r=n;
			l++;
			o=-1;
		}
		else if(r<1)
		{
			r=1;
			l++;
			o=1;
		}
	}
	return 0;
}


