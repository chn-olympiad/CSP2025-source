#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],mark;
bool flag;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	mark=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int l=1,r=1,cnt=1;
	while(l<=n&&r<=m)
	{
		if(flag==1)
		{
			break;
		}
		while(l<=n)
		{
			if(a[cnt]==mark)
			{
				cout<<r<<" "<<l;
				flag=1;
			}
			l++,cnt++;
		}
		if(flag==1)
		{
			break;
		}
		l--,r++;
		if(a[cnt]==mark)
		{
				cout<<r<<" "<<l;
				flag=1;
		}
		if(flag==1)
		{
			break;
		}
		while(l>=1)
		{
			if(a[cnt]==mark)
			{
				cout<<r<<" "<<l;
				flag=1;
			}
			l--,cnt++;
		}
		if(flag==1)
		{
			break;
		}
		l++,r++;
		if(a[cnt]==mark)
		{
			cout<<r<<" "<<l;
			flag=1;
		}
	}
	return 0;
}
