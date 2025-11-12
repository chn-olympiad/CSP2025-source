#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	string s1,s2;
}a[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].s1 >> a[i].s2;
	}
	for(int i = 1;i <= q;i++)
	{
		string t1,t2;
		cin >> t1 >> t2;
		int cnt = 0;
		if(t1.size() != t2.size())
		{
			cnt = -1;
		}
		if(cnt == -1) continue;
		for(int j = 1;j <= n;j++)
		{
			for(int k = 0;k < t1.size();k++)
			{
				if(cnt == -1) continue;
				string t = t1.substr(k,a[j].s1.size());
				string tt = t1;
				if(t == a[j].s1)
				{
					for(int l = 0;l < t.size();l++) tt[k + l] = a[j].s2[l];
					if(tt == t2) cnt++;
				}
			}
		}
		if(cnt != -1 && cnt != 0) cout << cnt << endl;
		else cout << 0 << endl;
	}
	return 0;
}
