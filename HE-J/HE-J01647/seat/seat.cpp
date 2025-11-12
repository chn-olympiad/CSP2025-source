#include <bits/stdc++.h>
using namespace std;
int n,m,x;
int a[105],vis[105];
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
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int bianhao,cnt=0;
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==x)
		{
			bianhao=i;
			break;
		}
	}
	int lie2;
	if(!(bianhao%n))
	{
		cout<<bianhao/n;
		lie2=bianhao/n;
	}
	else
	{
		cout<<bianhao/n+1;
		lie2=bianhao/n+1;
	}
	cout<<" ";
    if(bianhao%(2*n)<=n)
    {
    	cout<<bianhao%(2*n);
	}
	else
	{
		cout<<n-(bianhao%(2*n)-n)+1;
	}
	return 0;
}
