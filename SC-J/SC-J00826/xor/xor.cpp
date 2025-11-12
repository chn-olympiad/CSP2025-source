#include<bits/stdc++.h>
#define i128 __int128
#define ll long long
#define db long double
#define Pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N=5e5+10;

int n,k,ans,p[N],s[N],b[N<<2];

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k; int la=-1;
	memset(b,0x3f,sizeof b); b[0]=0;
	for(int i=1;i<=n;++i) cin>>p[i],s[i]=s[i-1]^p[i];
	for(int i=1;i<=n;++i)
	{
		if(b[s[i]^k]<=n)
		{
			for(int j=la+1;j<i;++j)
				if(b[s[j]]==j) b[s[j]]=n+1;
			++ans; la=i-1;
		}
		b[s[i]]=i;
	}
	cout<<ans;
	return 0;
}