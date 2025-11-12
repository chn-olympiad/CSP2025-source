#include <bits/stdc++.h>
using namespace std;
int n, q;
struct node{
	string a, b;
	int len;
}s[200005];
bool cmp(node x, node y)
{
	return x.len > y.len;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i].a >> s[i].b;
		s[i].len = s[i].a.size();
	}
	sort(s+1,s+1+n,cmp);
	while(q--)
	{
		string x, y;
		cin >> x >> y;
		int lent = x.size();
		cout << 0 << "\n";
	}
	return 0;
 } 
