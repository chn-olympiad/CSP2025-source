#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=6e5+5;
int n,q,ans;
bool vis[1005][2005][2];
string s[N][2],t[2];
bool cmp(int i,int l,int pos)
{
	for(int j=0;j<s[i][pos].size();++j)
		if(s[i][pos][j]!=t[pos][j+l])
			return 0;
	return 1; 
}
void solve(int l,int r)
{
	for(int i=1;i<=n;++i)
	{
		if(r-l+1!=s[i][0].size())
			continue;
		if(vis[i][l][0]||vis[i][r][1])
			continue;
		if(cmp(i,l,0)&&cmp(i,l,1))
		{
//			cout<<i<<' '<<l<<' '<<r<<'\n';
			ans++;
			vis[i][l][0]=vis[i][r][1]=1;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s[i][0]>>s[i][1];
	while(q--)
	{
		cin>>t[0]>>t[1];
		int idl=-1,idr=-1;
		for(int i=0;i<t[0].size();++i)
			if(t[0][i]!=t[1][i])
			{
				idl=i;
				break;
			}
		for(int i=t[0].size()-1;i>=0;--i)
			if(t[0][i]!=t[1][i])
			{
				idr=i;
				break;
			}
//		cout<<idl<<' '<<idr<<'\n';
		ans=0;
		for(int i=0;idl-i>=0;++i)
			for(int j=0;idr+j<t[0].size();++j)
				solve(idl-i,idr+j);
		cout<<ans<<'\n';
		for(int i=1;i<=n;++i)
			for(int j=0;j<t[0].size();++j)
				vis[i][j][0]=vis[i][j][1]=0;
	}
	return 0;
}
