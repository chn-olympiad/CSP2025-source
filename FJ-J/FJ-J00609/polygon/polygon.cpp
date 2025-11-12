#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005];//max
int c[5005];//zonghe
int f(int t,int bian)
{
	if(b[t+bian-1]>b[t-1])
	{
		return b[t+bian-1];
	}
	else
	{
		int maxn=-1;
		for(int i=t;i<=t+bian-1;i++)
		{
			maxn=max(maxn,a[i]);
		}
		return maxn;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long zong=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=max(b[i-1],a[i]);
		c[i]=c[i-1]+a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			if(c[j+i-1]-c[j-1]>f(j,i)*2)
			{
				//cout<<c[j+i-1]-c[j-1]<<" "<<f(j,i)<<endl;
				zong=(zong+1)%998244353;
			}
		}
	}
	cout<<zong;
	return 0;
}