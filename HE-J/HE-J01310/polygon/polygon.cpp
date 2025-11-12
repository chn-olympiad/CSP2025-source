#include<bits/stdc++.h>
using namespace std;
int a[5010],v[5010],b[5010],maxn=INT_MIN;
long long sum,ans=0;
int n,cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
		sum+=a[i];
	}
	maxn*=2;
	if(sum>maxn)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
