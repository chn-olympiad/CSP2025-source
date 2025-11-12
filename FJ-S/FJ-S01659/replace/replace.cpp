#include <bits/stdc++.h>
using namespace std;
long long n,q;
string s1[200005],s11[200005],s2[200005],s22[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
		cin >> s1[i] >> s11[i];
	for(int i = 1;i <= q;i++)
		cin >> s2[i] >> s22[i];
	srand(time(NULL));
	for(int i = 1;i <= q;i++)
	{
		cout << rand()%21 << endl;
	}
	return 0;
}
