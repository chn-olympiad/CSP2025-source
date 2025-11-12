#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,a[105],b;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	int l=n*m;
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=l;i++)
	{
		if(a[i]==b)
		{
			int u=i/n;
			int p=i%n;
			if((u+1)%2==1&&p!=0)
			{
				r=p;
				c=u+1;
			}
			else if((u+1)%2==0&&p!=0)
			{
				c=u+1;
				r=n-p+1;
			}
			else if(u%2==1&&p==0)
			{
				c=u;
				r=n;
			}
			else
			{
				c=u;
				r=1;
			}
			cout<<c<<" "<<r;
			break;
		}
	}
	return 0;
}
