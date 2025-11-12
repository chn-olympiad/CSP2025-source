#include <bits/stdc++.h>
using namespace std;

struct emm {
	string s1;
	string s2;
}t;

int n,q,ans;
string str1,str2;
vector<emm> a;

void bdfs (string x,string y)
{
	for (int i = 0; i < a.size(); i++) {
		if (x.find(a[i].s1) == -1) continue;
		string tmpp = x;
		tmpp.replace(x.find(a[i].s1),a[i].s1.size(),a[i].s2);
		if (tmpp == y) ans++;
	}
}

int main ()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> t.s1 >> t.s2;
		a.push_back(t);
	}
	while (q--)
	{
		ans = 0;
		cin >> str1 >> str2;
		bdfs(str1,str2);
		cout << ans << endl;
	}
	return 0;
}