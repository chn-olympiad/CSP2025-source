#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, q;
struct change
{
	string st, ed;
} rules[N];

int main()
{
	ios::sync_with_stdio(0);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i )
		cin >> rules[i].st >> rules[i].ed;
	
	map <string, string> trans;
	
	for (int i = 1; i <= n; ++ i )
		trans[rules[i].st] = rules[i].ed;
	
	for (int i = 1; i <= q; ++ i )
	{
		
	}
	return 0;
}
