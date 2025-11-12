#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int s1len[200005];
int flag[5000005];
int f[5000005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]; cin>>s2[i];
		s1len[i]=s1[i].length();
	}
	for(int iii=1;iii<=q;iii++)
	{
		int ans=0;
		string s,t; cin>>s>>t;
		if(s.length()!=t.length())
		{
			cout<<0<<'\n';
			continue;
		}
		int slen=s.length();
		for(int i=0;i<slen;i++)
		{
			if(s[i]!=t[i]) flag[i]=1;
			else flag[i]=0;
			if(i>=1) flag[i]+=flag[i-1];
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=0;i<=s1len[k];i++) f[i]=0;
			int j=0;
			for(int i=1;i<s1len[k];i++)
			{
				while(j>0&&s1[k][i]!=s1[k][j]) j=f[j-1];
				if(s1[k][i]==s1[k][j]) j++;
				f[i]=j;
			}
			j=0;
			for(int i=0;i<slen;i++)
			{
				while(j>0&&s[i]!=s1[k][j]) j=f[j-1];
				if(s[i]==s1[k][j]) j++;
				if(j==s1len[k])
				{
					if(flag[i]-flag[i-s1len[k]]==flag[slen-1])
					{
						int h=1,now=0;
						for(int l=i-s1len[k]+1;l<=i;l++)
						{
							if(t[l]!=s2[k][now])
							{
								h=0; break;
							}
							now++;
						}
						ans+=h;
					}
					j=f[j-1];
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
