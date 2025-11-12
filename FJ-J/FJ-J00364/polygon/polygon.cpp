#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],s=0,maxn=INT_MAX;
long long ans;
bool can(int i,int j)
{
	s=0;
	maxn=INT_MAX;
	for(int p=i;p<=j;p++)
	{
		s+=a[p];
		maxn=max(maxn,a[p]);
	}
	return s>maxn*2;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+2;j<=n;j++)
		{
			if(can(i,j))
				ans++;
		}
	cout<<ans%998244353;
	return 0;
}
