#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353,N=505;
int n,m,c[N];
string s;
int calc(int x)
{
	int ans=1;
	for(int i=1;i<=x;++i)
		ans=ans*i%mod;
	return ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)
		cin>>c[i];
	bool ok=1;
	for(int i=0;i<s.size();++i)
		if(s[i]!='1')
		{
			ok=0;
			break;
		}
	if(ok)//Ëæ±ãÅÅÁÐ 
	{
		int cnt=0;
		for(int i=1;i<=n;++i)
			if(!c[i])
				cnt++;
		cout<<calc(n-cnt);
		return 0;
	}
	return 0;
}
