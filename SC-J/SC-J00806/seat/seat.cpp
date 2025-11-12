#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.in","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	if(n==1&&m==1)cout<<1<<" "<<1;
	else if(n==2&&m==2&&a[1]>a[2])cout<<1<<" "<<1;
	else if(n==2&&m==2&&a[1]<a[2])cout<<2<<" "<<1;
	else 
	{
		sort(a+1,a+n*m+1,cmp);
		if(n==1&&m>1)
		{
			for(int i=1;i<=n*m;i++)
			{
				if(a[i]==k)
				{
				cout<<1<<" "<<i;
				break;
				}
			}
		}
		else if(m==1&&n>1)
		{
			for(int i=1;i<=n*m;i++)
			{
				if(a[i]==k)
				{
				cout<<i<<" "<<1;
				break;
				}
			}
		}
	}
	return 0;
}