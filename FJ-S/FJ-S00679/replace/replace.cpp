#include<bits/stdc++.h>
#define N 200005
#define B 29
#define M 5000005
#define mod 1000013
using namespace std;
int n,q;
string s[N][2],t[N][2];
long long pw[M];
unordered_multiset<int> mp[mod];
vector<int> h[N][2];
long long gethsh(int i,int j,int l,int r)
{
	if(l>r) return 0;
	if(l==0) return h[i][j][r];
	return (h[i][j][r]-h[i][j][l-1]*pw[r-l+1]%mod+mod)%mod;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    pw[0]=1;
    for(int i=1;i<M;i++) pw[i]=pw[i-1]*B%mod;
	cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
    for(int i=1;i<=q;i++) cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=n;i++)
	{
		long long hsh=0;
		for(int j=0;j<s[i][0].size();j++) hsh=(hsh*B%mod+s[i][0][j]-'a'+1)%mod;
		long long hsh2=0;
		for(int j=0;j<s[i][1].size();j++) hsh2=(hsh2*B%mod+s[i][1][j]-'a'+1)%mod;
//		cerr<<hsh<<' '<<hsh2<<'\n';
		mp[hsh].insert(hsh2);
	}
	for(int i=1;i<=q;i++)
	{
		long long ans=0;
		for(int j=0;j<=1;j++)
		{
			h[i][j].resize(t[i][j].size()+1);
			h[i][j][0]=t[i][j][0]-'a'+1;
			for(int k=1;k<t[i][j].size();k++) h[i][j][k]=(h[i][j][k-1]*B%mod+t[i][j][k]-'a'+1)%mod;
		}
		int len=t[i][0].size();
//		cerr<<'*'<<gethsh(1,0,3,4)<<' '<<gethsh(1,1,3,4)<<'\n';
		for(int l=0;l<len;l++) for(int r=l;r<len;r++)
		{
			if(gethsh(i,0,0,l-1)==gethsh(i,1,0,l-1)&&gethsh(i,0,r+1,len-1)==gethsh(i,1,r+1,len-1))
			{
//				cerr<<i<<' '<<l<<' '<<r<<' '<<gethsh(i,0,l,r)<<' '<<gethsh(i,1,l,r)<<'\n';
				ans+=mp[gethsh(i,0,l,r)].count(gethsh(i,1,l,r));
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
