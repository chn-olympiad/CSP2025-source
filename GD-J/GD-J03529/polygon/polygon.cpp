#include<bits/stdc++.h>
using namespace std;
long long n,m,s[5005],ans,sum,a[1000005];
void dfs(long long x)
{	
	if(x>n)
	return;

	if(a[x]!=1)
	{
		for(int i=x;i<=n;i++)	
		{
			sum+=s[i];
			a[i]=1;
			if(sum>s[x]*2)
			ans++;
			dfs(i+1);
			a[i]=0;
			sum-=s[i];
		}
	}
}
int main(){
	//freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+1+n);
	dfs(1);
	cout<<ans%998244353;
	return 0;
}
