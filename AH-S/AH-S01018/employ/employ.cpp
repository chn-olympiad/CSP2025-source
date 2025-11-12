#include<bits/stdc++.h>
//#define LL long long

using namespace std;

typedef long long LL;
typedef pair<LL,pair<LL,LL>> piii;

const int mod=998244353;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		int c;
		cin>>c;
	}
	
	int ans=0;
	for(int i=m;i<=n;i++)
	{
		int res=1;
		for(int j=0;j<i;j++)
		{
			res=(1ll*res*(n-j))%mod;
		}
		ans=(ans+res)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
//161088479
