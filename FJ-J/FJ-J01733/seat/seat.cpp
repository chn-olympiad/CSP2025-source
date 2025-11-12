#include<bits/stdc++.h>
int a[1000005];
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==x)
		{
			int c=(n*m-i+1)/m,r;
			if((n*m-i+1)%m!=0)c++;
			if(c%2==1) r=(n*m-i+1)%m;
			else r=n-(n*m-i+1)%m+1;
			if(r==0)r=n;
			cout<<c<<' '<<r;
			break;
		}
	}
	return 0;
}
