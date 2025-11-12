#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)p=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int b;
	for(int i=1;i<=n*m;i++)
	{
		if(p==a[i])b=i;
	}
	cout<<(b-1)/n+1<<" ";
	int t=b%n;
	if(t==0)t=n;
	if(((b-1)/n+1)%2==0)
	{
		cout<<n-t+1;
	}
	else {
		cout<<t; 
	}
	return 0;
}