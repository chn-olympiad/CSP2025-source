#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=44777444447777777;
const int base=29;
int n,q,l[200005];
string s[200005][4],t[4];
ll hsh[200005][4],h0[200005],h1[200005],mi[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		hsh[i][0]=hsh[i][1]=0;
		l[i]=s[i][0].length();
		mi[i]=1;
		for(int j=0;j<l[i];j++)
		{
			hsh[i][0]=(hsh[i][0]*base%mod+s[i][0][j]-'a'+1)%mod;
			hsh[i][1]=(hsh[i][1]*base%mod+s[i][1][j]-'a'+1)%mod;
			mi[i]=mi[i]*base%mod;
		}
	}
	ll ans;
	while(q--)
	{
		cin>>t[0]>>t[1];
		if(t[0].length()!=t[1].length())
		{
			cout<<0<<'\n';
			continue;
		}
		ans=0,h0[0]=h1[0]=0;
		int len=t[0].length(),ls=0,rs=n+1;
		while(ls+1<=len&&t[0][ls]==t[1][ls])ls++;
		while(rs-1>=1)
		{
			if(t[0][rs-2]!=t[1][rs-2])break;
			rs--;
		}
		for(int i=0;i<len;i++)
		{
			h0[i+1]=(h0[i]*base%mod+t[0][i]-'a'+1)%mod;
			h1[i+1]=(h1[i]*base%mod+t[1][i]-'a'+1)%mod;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j+l[i]<=len;j++)
			{
				if(j+1>ls+1||j+l[i]<rs-1)continue;
				if((h0[j+l[i]]-h0[j]*mi[i]%mod+mod)%mod==hsh[i][0]&&(h1[j+l[i]]-h1[j]*mi[i]%mod+mod)%mod==hsh[i][1])
				{
					ans++;
					cout<<i<<' '<<j<<endl;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
