#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m,li=1,ro=1,num;
int a[maxn];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1) num=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(num==a[i])
		{
			cout<<li<<' '<<ro;
			break;
		}
		ro+=(li%2?1:-1);
		if(ro==n+1)
		{
			ro=n;
			li++;
		}
		if(ro==0)
		{
			ro=1;
			li++;
		}
	}
	return 0;
}