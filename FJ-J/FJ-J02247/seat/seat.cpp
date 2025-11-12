#include<bits/stdc++.h>
using namespace std;
struct node
{
	int number;
	bool f;
}a[105];
bool cmp(node x,node y)
{
	return x.number>y.number;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].number;
		if(i==1) a[i].f=1;
	}
	sort(a+1,a+m*n+1,cmp);
	int t;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].f)
		{
			t=i;
			break;
		}
	}
	if(t%(2*n)<=n)
	{
		cout<<(t-1)/n+1<<" "<<(t-1)%n+1;
	}
	else
	{
		cout<<(t-1)/n+1<<" "<<n-((t-1)%n);
	}
	return 0;
}
