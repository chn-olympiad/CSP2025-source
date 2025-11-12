#include <bits/stdc++.h>
using namespace std;
struct node{
	int s;
	bool f=false;
}a[105];
int n,m;
int cmp(node x,node y)
{
	return x.s>y.s;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].s;
	a[1].f=true;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i*m-m+j].f==true)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[i*m-m+j-n+1].f==true)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
