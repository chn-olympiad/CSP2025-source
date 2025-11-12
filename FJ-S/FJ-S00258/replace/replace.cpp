#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=2010;
int n,q;
int len[N],kmp[N][M];
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].length(); s1[i]=" "+s1[i];
		for(int j=2,p=0;j<=len[i];j++)
		{
			while(s1[i][j]!=s1[i][p+1] && p) p=kmp[i][p];
			if(s1[i][j]==s1[i][p+1]) p++;
			kmp[i][j]=p;
		}
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int L=t1.length(),ans=0; t1=" "+t1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1,p=0;j<=L;j++)
			{
				while(t1[j]!=s1[i][p+1] && p) p=kmp[i][p];
				if(t1[j]==s1[i][p+1]) p++;
//				cout<<p<<' '<<len[i]<<endl;
				if(p==len[i])
				{
					string s="";
					for(int k=1;k<=j-len[i];k++)
						s+=t1[k];
					for(int k=0;k<s2[i].length();k++)
						s+=s2[i][k];
					for(int k=j+1;k<=L;k++)
						s+=t1[k];
					if(s==t2) ans++;
					p=kmp[i][p];
				}
//				cout<<1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
