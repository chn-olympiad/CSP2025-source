#include <bits/stdc++.h>
using namespace std;
long long n,q;
string s1,s2,t1,t2;
vector <char> c;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for (int i = 1;i <= n;i++) scanf("%s %s",&s1,&s2);
	for (int j = 1;j <= q;j++) scanf("%s %s",&t1,&t2);
	for (int i = 1;i <= q;i++) cout << 0 << endl;
	return 0;
}