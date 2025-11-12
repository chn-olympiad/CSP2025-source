#include <bits/stdc++.h>
using namespace std;
long long n,maxn,cnt,a[5005];
/*
bool cmp(int n,int x[n])
{
	for(int i=1;i<=n;i++)
	{
		cnt+=x[i];
		maxn=max(x[i],maxn);
	}
	if(cnt>2*maxn)
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt+=a[i];
		maxn=max(a[i],maxn);
	}
	if(cnt>2*maxn&&n>=3)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
