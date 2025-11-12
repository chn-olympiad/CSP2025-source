#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,num;
struct Node
{
	int x,id;
}a[110];
bool cmp(Node a,Node b)
{
	return a.x>b.x;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			num=i;
			break;
		}
	}
	if((int)(ceil(num*1.0/n))%2==1)
	{
		if(num%n==0)
		{
			cout<<(int)(ceil(num*1.0/n))<<" "<<num%n+n;
		}
		else
		{
			cout<<(int)(ceil(num*1.0/n))<<" "<<num%n;
		}
	}
	else
	{
		if(num%n==0)
		{
			cout<<(int)(ceil(num*1.0/n))<<" "<<1;
		}
		else
		{
			cout<<(int)(ceil(num*1.0/n))<<" "<<n-num%n+1;
		}
	}
	return 0;
}
