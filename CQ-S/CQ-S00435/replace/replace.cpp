#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,mod=998244353;
int n,Q;
string s[N][2];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1]; 
	}
	while(Q--)
	{
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<"0\n";
			continue;
		}
		int st=-1,e=-1;
		for(int i=0;i<t1.size();i++)
		{
			if(t1[i]!=t2[i])
			{
				st=i;
				break;
			}
		}
		for(int i=t1.size()-1;i>=0;i--)
		{
			if(t1[i]!=t2[i])
			{
				e=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i][0].size()<e-st+1)continue;
			for(int l=0;l<t1.size()-s[i][0].size()+1;l++)
			{
				bool flag=0;
				int r=l+s[i][0].size()-1;
				for(int j=l;j<=r;j++)
				{
					if(t1[j]!=s[i][0][j-l]||t2[j]!=s[i][1][j-l])
					{
						flag=1;
						break;
					}
				}
				if(!flag)
				{
					ans++;
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
