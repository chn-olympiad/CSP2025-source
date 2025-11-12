#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][2],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		for (int i=1;i<=n;i++)
		{
			if (s[i][0].size() <=t1.size() ){
				for (int j=0;j<=t1.size()-s[i][0].size();j++)
				{
					string k=t1.substr(j,s[i][0].size() );	
					if (k==s[i][0])
					{
						string g=t1;
						g.replace(j,s[i][1].size(),s[i][1]);;
						if (g==t2)
						{
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
