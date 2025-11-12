#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int s[520];
bool t;
long long ans;
int main()
{
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    t=1;
    for(int i=1;i<=n;i++)
    {
    	cin>>s[i];
    	if(s[i]!=1)
    		t=0;
	}
	ans=1;
	if(t)
	{
		for(int i=1;i<=n;i++)
			ans=(ans%mod)*i%mod;
		cout<<ans;
	}
    return 0;
}
