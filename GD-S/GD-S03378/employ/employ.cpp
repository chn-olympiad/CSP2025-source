#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)n--;
	}
	long long ans=1;
	for(int i=1;i<=n;i++)ans*=i,ans%=998244353;
	printf("%lld",ans);	 
}	
