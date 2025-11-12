#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,sum,c,r,cnt;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	//输入
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sum=a[1];
	//排序
	sort(a+1,a+n*m+1,cmp);
	//找到排名
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==sum)
		{
			cnt=i;
		}
	}
	//处理几列几行
	c=cnt/n;
	if(cnt%n!=0)
	{
		c++;
	}
	if(c%2==0)
	{
		if(cnt%n==0)
		{
			r=1;
		}
		else
		{
			r=n-cnt%n+1;
		}
	}
	else
	{
		if(cnt%n==0)
		{
			r=n;
		}
		else
		{
			r=cnt%n;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}