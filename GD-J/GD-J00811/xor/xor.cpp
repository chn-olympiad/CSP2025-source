#include<bits/stdc++.h>
using namespace std;
const long long N=5*100000;
long long n,k,a[N+5],ans,maxn,s[N+5],num[N+5];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long post=i,t=0;
		while(post!=n+1)
		{
			t=(t^a[post]);
			if(t==k)
			{
				s[i]=post;
				break;
			}
			else if(post==n)
			{
				s[i]=-1;
			}
			post++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		num[i]=1;
		for(int j=1;j<=i-1;j++)
		{
			if(s[j]<i&&s[j]!=-1) 
			{
				num[i]=max(num[j]+1,num[i]);
			}
		}
		maxn=max(maxn,num[i]);
	}
	cout<<maxn;
	return 0;
} 
