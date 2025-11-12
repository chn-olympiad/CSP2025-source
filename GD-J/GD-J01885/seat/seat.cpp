#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+10]={},a1;
	cin>>a[1];
	a1=a[1];
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==a1) 
		{
			a1=i;
			break;
		}
	}
	int x,y,d,ans;
	if(n%2==0) x=1,y=m,d=1,ans=1;
	if(n%2==1) x=n,y=m,d=-1,ans=1;
	for(int i=1;i<=n*m;i++)
	{
		if(ans==a1) 
		{
			cout<<y<<" "<<x;
			break;
		}
		if(x+d<=n&&x+d>=1) 
		{
			x+=d;
			ans++;
		}
		else if(x+d>n&&d==1)
		{
			d=-1;
			y-=1;
			ans++;
		}
		else if(x+d<1&&d==-1)
		{
			d=1;
			y-=1;
			ans++;
		}
	}
	return 0;
}
