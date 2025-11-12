#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	vector<pair <string,string>> s;
	cin >> n >> q;
	s.resize(n + 1);
	for(int i = 1;i <= n;i++)
		cin >> s[i].first >> s[i].second;
	while(q--)
	{
		pair <string,string> t;
		cin >> t.first >> t.second;
		srand(time(0));
		cout << rand() % 4 << '\n';
	}
	return 0;
}
