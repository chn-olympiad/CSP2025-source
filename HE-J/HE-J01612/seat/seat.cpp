#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int c,int d)
{
	return c>d;
}
int main()
{
	freopen("seat3.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	int l=1,r=n*m;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(a[mid]==x)
		{
			l=mid;
			break;
		}
		if(a[mid]>x)l=mid+1;
		else r=mid;
	}
	int c=(l+n-1)/n;
	if(c%2==1)cout<<c<<" "<<(l-1)%n+1;
	else cout<<c<<" "<<n-l%n+1;
	return 0;
}
