#include<bits/stdc++.h>
using namespace std;
int n,m,len,x,y,d;
int a[200],b;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++) cin>>a[i];
	b=a[1];
	sort(a+1,a+1+len);
	x=y=d=1;
	for(int i=len;i>=1;i--)
	{
		if(a[i]==b)
		{
			cout<<x<<" "<<y<<"\n";
			break;
		}
		if(y+d<1||y+d>n)
		{
			x++;
			d=-d;
		}
		else y+=d;
	}
}