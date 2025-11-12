#include<bits/stdc++.h>
using namespace std;
string s[200005][2],t[200005][2];
int n,q;
int ck1()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<(int)s[i][j].size();k++)
			{
				if(s[i][j][k]!='a'&&s[i][j][k]!='b')
					return 0;
				else if(s[i][j][k]=='b')
					cnt++;
				if(cnt!=1)
					return 0;
			}
	for(int i=1;i<=q;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<(int)t[i][j].size();k++)
			{
				if(t[i][j][k]!='a'&&t[i][j][k]!='b')
					return 0;
				else if(t[i][j][k]=='b')
					cnt++;
				if(cnt!=1)
					return 0;
			}
	return 1;
}
namespace Main1{
	int f[2000005];
	int fd(string x)
	{
		for(int i=0;i<(int)x.size();i++)
			if(x[i]=='b')
				return i;
		return -1435123;
	}
	void main()
	{
		vector<int>vx;
		for(int i=1;i<=n;i++)
		{
			int tx=fd(s[i][0])-fd(s[i][1]);
		}
		for(int i=1;i<=q;i++)
		{
			if(t[i][0].size()!=t[i][1].size())
			{
				cout<<"0\n";
				continue;
			}
			int tx=fd(t[i][0])-fd(t[i][1]);
			cout<<f[tx+1000000]<<"\n";
		}
	}
}
signed main()
{
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)
		cin>>t[i][0]>>t[i][1];
	if(ck1())Main1::main();
	return 0;
}
