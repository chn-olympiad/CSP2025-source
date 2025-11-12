#include<bits/stdc++.h>
using namespace std;
int c,r,n,m;
struct stu{
	int score;
	int id;
}a[105];
int cmp(stu a,stu b)
{
	return a.score>b.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			if(i%n==0)
			{
				c=i/n;
			}
			if(i%n!=0)
			{
				c=i/n+1;
			}
			if(c%2==0)
			{
				if(i%n==0)
				{
					r=1;
				}
				if(i%n!=0)
				{
					r=n-i%n+1;
				}
			}
			if(c%2!=0)
			{
				if(i%n==0)
				{
					r=n;
				}
				if(i%n!=0)
				{
					r=i%n;
				}
			}
			cout<<c<<" "<<r;
			return 0;
		}	
	}
	return 0;
}
