#include"bits/stdc++.h"
using namespace std;
int n,m,a[110];
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
	int aa=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==aa)
		{
			cout<<(i-1)/n+1<<" ";
			if(((i-1)/n+1)%2==0)cout<<n-(i%n)+1;
			else if(i%n!=0)cout<<i%n;
			else cout<<n;
			break;
		}
	}
	return 0;
}
