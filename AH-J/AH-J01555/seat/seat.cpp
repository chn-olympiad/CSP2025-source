#include<bits/stdc++.h>
using namespace std;
int a[105],t,c;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,n,m,s1,s2;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(t==a[i])
		{
			c=i;
			break;
		}
	}
	s1=c/n;
	if(s1*n!=c)
	{
		s1++;
	}
	if(s1%2!=0)
	{
		s2=c-n*(s1-1);
	}
	else
	{
		s2=n+1-(c-n*(s1-1));
	}
	cout<<s1<<" "<<s2;
	return 0;
}
