#include <iostream>
#define endl '\n'
using namespace std;
typedef long long int lli;
int n,q,ans;
string a,b,tmp;
pair<string,string> map[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> map[i].first >> map[i].second;
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> a >> b;
		ans = 0;
		for(int j = 1,k = 0;j <= n;j++)
		{
			k = a.find(map[j].first);
			tmp = a;
//			cerr << map[j].first << ' ' << k << endl;
			if(~k)
			{
//				cerr << tmp << ' ' << map[j].second << endl;
				tmp.replace(tmp.begin() + k,tmp.begin() + k + map[j].first.size(),map[j].second);
//				cerr << tmp << endl;
				if(tmp == b)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}