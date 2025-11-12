#include<bits/stdc++.h>
using namespace std;
const int N=5001;
int a[N];
const int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	int tot=n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]==0) tot--;
	}
	if(tot<m)
	{
		printf("%d",0);
		return 0;
	}
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=(ans%mod)*i;
		ans=ans%mod;
	}
	printf("%lld",ans);
	return 0;
}