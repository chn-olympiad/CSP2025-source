#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
const int maxn=2e5+5;
int n,q,ans;
string t[maxn][2],s0,s1;
void solve()
{
	ans=0;
	cin>>s0>>s1;
	for(int i=0;i<s0.size();i++)
	{
		for(int j=1;j<=n;j++)
		{
			int flag=0;
			string tmp=s0;
			for(int k=0;k<t[j][0].size();k++)
				if(i+k>=s0.size()||s0[i+k]!=t[j][0][k])
				{
					flag=1;
					break;
				}
			if(flag)continue;
			for(int k=0;k<t[j][0].size();k++)
				tmp[i+k]=t[j][1][k];
			if(tmp==s1)ans++;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=q;i++)
		solve();
	return 0;
}
