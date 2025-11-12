#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	long long a[1001];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	long long R=a[1];
	long double bj;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			bj=i;
			break;
		}
	}
	long long l=ceil(bj/n);
	long long wz=bj;
	if(l%2==1)
	{
		if(wz%n!=0)cout<<l<<" "<<wz%n;
		else cout<<l<<" "<<n;
	}
	else
	{
		if(wz%n!=0)cout<<l<<" "<<n-(wz%n)+1;
		else cout<<l<<" "<<1;
	}
	return 0;
}
