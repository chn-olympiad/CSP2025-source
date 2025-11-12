#include<bits/stdc++.h>
using namespace std;
long long n,m,b,d,c,e;
struct sb
{
	long long fs;
	int bh;
}a[1515];
bool cmp(sb s1,sb s2)
{
	return s1.fs>s2.fs;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=m*n;j++)
	{
		cin>>a[j].fs;
		if(j==1)
		{
			a[j].bh=1;
		}
		else a[j].bh=0;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].bh==1)
		{
			if(i<=n)
				cout<<1;
			else 
				cout<<i/n+1;
			if(i%n!=0)
				cout<<" "<<i%n;
			else
				cout<<" "<<n;
		}
	}
	return 0;
}
