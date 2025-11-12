#include<bits/stdc++.h>
using namespace std;
int n,a[5010],maxn,cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
		cnt+=a[i];
	}
	if(n<3||cnt<maxn*2)
	{
		cout<<0;
		return 0;
	}
	return 0;
}
