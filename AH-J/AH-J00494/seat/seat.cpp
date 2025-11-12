#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int a,id;
}p[105];
bool cmp(Node x,Node y)
{
	return x.a>y.a;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int i;
	for(i=1;i<=n*m;i++)
	{
		cin>>p[i].a;
		p[i].id=i;
	}
	sort(p+1,p+1+n*m,cmp);
	int c;
	for(i=1;i<=n*m;i++)
	{
		if(p[i].id==1)
		{
			c=i;
			break;
		}
	}
	if(c%m==0)
	{
		cout<<c/n<<" ";
		if((c/n)%2==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n;
		}
	}
	else
	{
		int t=c;
		cout<<c/n+1<<" ";
		c=c%n;
		if((t/n+1)%2==0)
		{
			cout<<n-c+1;
		}
		else
		{
			cout<<c;
		}
	}
	return 0;
}
