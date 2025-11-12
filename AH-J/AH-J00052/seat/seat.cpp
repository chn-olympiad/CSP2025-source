#include<bits/stdc++.h>
using namespace std;
int a[110],n,m;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int R=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=0;
	for(int i=1;i<=n*m;i++)
	{
		if(c%2==1)
		{
			if(r==n)c++;
			else r++;
		}
		else if(c%2==0)
		{
			if(r==1)c++;
			else r--;
		}
		if(R==a[i])
		{
			cout<<c<<' '<<r<<endl;
			return 0;
		}
	}
	return 0;
}

