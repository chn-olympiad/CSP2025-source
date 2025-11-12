#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

int n,m;
int a[N];
struct aaa
{
	int a,bj;
}f[N];

bool cmp(aaa x,aaa y)
{
	return x.a>y.a;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>f[i].a;
		if(i==1)f[i].bj=1;
	}
	
	sort(f+1,f+1+n*m,cmp);
//		for(int i=1;i<=n*m;i++)cout<<f[i].a<<"   ";

	int num;
	int c,r;
	
	for(int i=1;i<=n*m;i++)
	{
		if(f[i].bj)num=i;
	}
//	cout<<num;
	
	c=num/n;
	if(num%n)c++;
//	cout<<c;

	if(c%2)
	{
		if(num%n==0)r=n;
		else r=num%n;
	}
	else 
	{
		if(num%n==0)r=1;
		else r=n-num%n+1;
	}
	
	cout<<c<<" "<<r;
	return 0;
 } 
 
// 4 5 19 11 12 13 14 15 20 21 22 23 10 24  100 98 97 96 95 94 93 92