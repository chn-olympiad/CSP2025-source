#include<bits/stdc++.h>
using namespace std;
int n, q;
string s[200005][2], t1, t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
	}
	for(int i = 1; i <= q; i++)
	{
		cin >> t1 >> t2;
		long long ans = 0;
		for(int j = 0; j < t1.size(); j++)
		{
			for(int k = 1; k <= n; k++)
			{
				if(t1[j] == s[k][1][0] && t2[j] == s[k][2][0])
				{
					bool flag = true;
					for(int a = 0; a < s[k][1].size(); a++)
					{
						if(t1[j+a] != s[k][1][a] || t2[j+a] != s[k][2][a])
							flag = false;
					}
					if(flag&&t1.substr(0,j)==t2.substr(0,j)&&t1.substr(j+s[k][1].size(),t1.size())==t2.substr(j+s[k][1].size(),t2.size()))
						ans+=flag;
					//cout << j << endl;
				}
			}
		}
		cout << ans << endl;
	}
	
}
