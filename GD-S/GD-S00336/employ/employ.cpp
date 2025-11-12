#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
int n,m,c[505],p[15];
ll jc[200005];
string s;
int ck1()
{
	int f=1;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0') f=0;
	return f;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0]=1;
	for(ll i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	/*if(ck1())
	{
		cout<<ts1();
		return 0;
	}*/
	if(n<=10)
	{
		int ans=0;
		for(int i=1;i<=n;i++) p[i]=i;
		do
		{
			int sum=0,cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i-1]=='0' || cnt>=c[p[i]]) cnt++;
				else sum++;
			}
			if(sum>=m) ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
}
/*
5 3
11111
0 0 0 1 2
*/
/*
Eventually,I decide to start Chrome. 
*/
