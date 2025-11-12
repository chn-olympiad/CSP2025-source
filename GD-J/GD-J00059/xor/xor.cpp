#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+10,M=2e6+10;
int a[N],fac[N];
vector<int>G[M];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	fac[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		fac[i]=fac[i-1]^a[i];
	}
	for(int i=n;i>=0;i--)
	{
		G[fac[i]].push_back(i);
	}
	int ans=0;
	int r=0;
	for(int i=0;i<=n;i++)
	{
		for(int p:G[k^fac[i]])
		{
			if(p<=i)
			{
				break;
			}
			if(i+1>r)
			{
				r=p;
				ans++;
			}
			if(p<r)
			{
				r=p;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
