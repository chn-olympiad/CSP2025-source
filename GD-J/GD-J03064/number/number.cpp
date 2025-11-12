#include<bits/stdc++.h>
#define int long long
using namespace std;
string str;
int cnt[17];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> str;
	for(int i = 0;i < str.size();i++)if('0' <= str[i] && str[i] <= '9')cnt[str[i] - '0']++;
	for(int i = 9;i >= 0;i--)for(int j = 1;j <= cnt[i];j++)cout << i;
	return 0;
}
