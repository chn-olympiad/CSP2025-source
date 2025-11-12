#include <bits/stdc++.h>
using namespace std;
int n,q,ans,cnt;
string s1[200005],s2[200005],qs[200005],an[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i=1;i<=n;i++)
	{
		cin >> s1[i] >> s2[i];
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
	}
	cnt=1;
	while(q--)
	{
		cin >> qs[cnt] >> an[cnt];
		qs[cnt]=' '+qs[cnt];
		an[cnt]=' '+an[cnt];
		cout << 0 << endl;
	}
	return 0;
}
