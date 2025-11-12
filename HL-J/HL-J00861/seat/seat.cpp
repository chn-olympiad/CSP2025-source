#include<bits/stdc++.h>
using namespace std;
int a[10001];
int n,m;
int c,w;
int ans1,ans2;
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
	c=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==c)
		{
			w=i;
		}
	}
	if(w%n==0)
	{
		ans1=w/n;
	}
	else
	{
		ans1=w/n+1;
	}
	int c1=0,c2=0;
	c1=(ans1-1)*n;
	c2=w-c1;
	if(ans1%2==0)
	{
		ans2=m-c2+1;
	}
	else
	{
		ans2=c2;
	}
	cout<<ans1<<" "<<ans2; 
	return 0;
}


