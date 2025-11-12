#include<bits/stdc++.h>
using namespace std;
long long N=998224353;
long long n,ans;
long long s[5005],v[5005];
void dfs(long long m,long long z,long long a,long long b)
{
	if(m>=3&&b*2<z)
	{
		ans++;
	}
	for(long long i=a+1;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			int num=max(b,s[i]);
			dfs(m+1,z+s[i],i,num);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>s[i];
    dfs(0,0,0,-1);
    ans%=N;
    cout<<ans;
    return 0;
}
