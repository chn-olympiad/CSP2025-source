#include<bits/stdc++.h>
using namespace std;
long long n,num;
long long a[5005];
const long long MOD=998244353;
bool check(int l,int m)
{
	long long sum=0,maxn=0;
	int i=l;
	while(m--)
	{
		sum+=a[i];
		maxn=max(a[i],maxn);
		i++;
	}
	return sum>2*maxn;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(check(i,j))
			{
				num+(n-i);
				num%=MOD;
			}
		}
	}
	cout<<num;
	return 0;
}
