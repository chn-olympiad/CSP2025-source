#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
string s;
int c[510],d[510];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]>0)d[0]++;
	}
	if(d[0]<m)
	{
		cout<<0;
		return 0;
	}
	int jc=1;
	for(int i=1;i<=n;i++)d[i]=i,jc*=i,jc%=mod;
	if(n<=18)
	{
		while(jc--)
		{
			int f=0;
			for(int i=1;i<=n;i++)
				if(s[i-1]=='0'||f>=c[d[i]])f++;	
			if(n-f>=m)ans++,ans%=mod;
			next_permutation(d+1,d+n+1);
		}
	}
	else ans=jc;
	cout<<ans<<endl;
	return 0;
}
