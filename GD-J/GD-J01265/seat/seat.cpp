#include<bits/stdc++.h>
using namespace std;
int cmd(int x,int y)
{
	return x>y;
}
int a[1000],ta,t,ansn,ansm;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>a[i];
	ta=a[1];
	sort(a+1,a+1+n*m,cmd);
	for(int i=1; i<=n*m; i++)
	{
		if(a[i]==ta)
		{
			t=i;
			break;
		}
	}
	if(t%n==0)
	{
		ansn=t/n;
	}
	else
	{
		ansn=t/n+1;
	}
	int shun=(t-(ansn-1)*n)-1;
	if(ansn%2==0)
	{
		ansm=n-shun;
	}
	if(ansn%2!=0)
	{
		ansm=1+shun;
	}
	cout<<ansn<<" "<<ansm;
	return 0;
}
