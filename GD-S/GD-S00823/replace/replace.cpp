#include<bits/stdc++.h>
using namespace std;
const int N=200001;
int n,q,ans;
string s1[N],s2[N],q1[N],q2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i<=n;i++) cin >> s1[i] >> s2[i];
	for(int i = 1;i<=q;i++) cin >> q1[i] >> q2[i];
	for(int ind = 1;ind<=q;ind++)
	{
		ans=0;
		for(int i = 1;i<=n;i++)
		{
			string query=q1[i];
			int len=s1[i].length();
			for(int j = 1;j<=n-len;j++)
			{
				bool flag=1;
				for(int x = 1;x<=len;x++)
				{
					if(s1[i][x]!=q1[ind][j+x])
					{
						flag=0;
						break;
					}
					else
					{
						query[j+x]=s1[i][x];
					}
				}
				if(flag)
				{
					int len=query.length();
					bool check=1;
					for(int i = 1;i<=len;i++)
					{
						if(query[i]!=q2[ind][i]) check=0;
					}
					if(check) ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
