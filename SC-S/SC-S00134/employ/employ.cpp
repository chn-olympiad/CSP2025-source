#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
string s;
int cnt;
int ans=1;
int m;
signed main(void)
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]=='1')
			++cnt;
	}
	if(cnt>0)
	{
		cout << n << '\n';
	}
	else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}