#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int f=a[1],xb,h=0,l=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==f) xb=n*m-i+1;
	}
	int bk=1;
	while(1)
	{
		bk++;
		if(bk>=n*m) break;
		if(xb>n)
		{
			xb-=n;
			l++;
		}
		else if(xb<=n)
		{
			l++;
			if(l%2==1) h=xb;
			else h=n-xb+1;
			break;
		}
    }
    cout<<l<<" "<<h;
	return 0;
}
