#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	int id=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			id=i-1;break;
		}
	}
	int c=0,r=0;
	c=id/n+1;
	if((id/n)%2==0) r=id-(c-1)*n+1;
	else r=n-(id-(c-1)*n);
	cout<<c<<' '<<r;
	return 0;
}
