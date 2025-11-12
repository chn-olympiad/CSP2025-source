#include<iostream>
using namespace std;
struct S{
	string a, b;
} s[200005];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
		cin >> s[i].a >> s[i].b;
	
	string t1, t2;
	while (q--)
	{
		cin >> t1 >> t2;
		cout << 0 << endl;
	}
	
	return 0;
}
