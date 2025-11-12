#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
map<pair<ull,ull>,int>mp;
const int N=2e5+5,M=5e6+5;
int n,q,len[N][2];
string s[N][2];
ull h1[N],h2[N],base[M],H1[M],H2[M];
mt19937_64 rnd(time(0));
ull getH1(int l,int r)
{
	if(l>r)return 0;
	return H1[r]-H1[l-1]*base[r-l+1];
}
ull getH2(int l,int r)
{
	if(l>r)return 0;
	return H2[r]-H2[l-1]*base[r-l+1];
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
		len[i][1]=s[i][1].length(),len[i][2]=s[i][2].length();
		s[i][1]='%'+s[i][1],s[i][2]='%'+s[i][2];
		int len=s[i][1].length()-1;
		h1[i]=0,h2[i]=0;
		for(int j=1;j<=len;j++)h1[i]=h1[i]*233+s[i][1][j]-'a'+1;
		for(int j=1;j<=len;j++)h2[i]=h2[i]*233+s[i][2][j]-'a'+1;
		if(mp.count({h1[i],h2[i]})){mp[{h1[i],h2[i]}]++,i--,n--;continue;}
		mp[{h1[i],h2[i]}]++;
	}
	base[0]=1;
	for(int i=1;i<=5e6;i++)base[i]=base[i-1]*233;
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int len1=t1.length(),len2=t2.length();
		if(t1.length()!=t2.length()){cout<<0<<'\n';continue;} 
		t1='%'+t1;t2='%'+t2;
		int ans=0;
		for(int i=1;i<=len1;i++)H1[i]=H1[i-1]*233+t1[i]-'a'+1;
		for(int i=1;i<=len2;i++)H2[i]=H2[i-1]*233+t2[i]-'a'+1;
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=len1-len[j][1]+1;i++)
			{
				if(getH1(i,i+len[j][1]-1)==h1[j])
				{
					if(getH2(i,i+len[j][1]-1)==h2[j]&&
					getH1(1,i-1)==getH2(1,i-1)&&
					getH1(i+len[j][1],len1)==getH2(i+len[j][1],len1))
					ans+=mp[{h1[j],h2[j]}];
				}
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
