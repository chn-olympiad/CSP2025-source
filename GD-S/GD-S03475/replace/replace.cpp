#include <iostream>
using namespace std;
const int N = 2e5+5;
string s[N][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2];
	for (int i = 1; i <= q; i++)
	{
		string t1,t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << 0 << "\n";
			continue;
		}
		int ans = 0;
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < t1.size(); k++)
			{
				if (k+s[j][2].size() > (int)t1.size()) break;
				//cout << (t1.substr(0,k)+s[j][2]+t1.substr(k+s[j][2].size(),t1.size()-k-s[j][2].size())) << endl;
				if (t1.substr(k,s[j][2].size()) == s[j][1] && t1.substr(0,k)+s[j][2]+t1.substr(k+s[j][2].size(),t1.size()-k-s[j][2].size()) == t2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
