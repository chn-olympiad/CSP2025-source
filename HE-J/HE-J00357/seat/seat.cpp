#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],x=1,y=1,k,w;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n*m-1;i++)scanf("%d",&a[i]);
	k=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){if(a[i]==k)
	{
		w=n*m-i;
		break;
	}
	}
	for(int i=2;i<=w;i++)
	{
		if((i-1)%n==0)x++;
		else 
		{
			if(x%2!=0)y++;
			if(x%2==0)y--;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
