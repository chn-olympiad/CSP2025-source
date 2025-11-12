#include<bits/stdc++.h>
using namespace std;
long long a[1010];
long long n,k,cnt,maxn=INT_MIN;
bool its()
{
	for(int i=1;i<=n;i++)
		if(a[i]!=1)
			return 0; 
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0&&its())
	{
		cout<<n/2;
		return 0;
	}
	for(int l=1;l<=n;l++)
	{
		for(int i=l;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				long long t=0;
				for(int k=i;k<=j;k++)
				{
					t=t^a[k];
				}
				if(t==k)
				{
					cnt++;
					i=j;
					break;
				}
			}
		}
		maxn=max(maxn,cnt);
		cnt=0;
	}
	cout<<maxn;
	return 0;
}
