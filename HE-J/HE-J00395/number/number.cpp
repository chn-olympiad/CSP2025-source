#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[20];
bool check()
{
	return cnt[0] != 0 && cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0 && cnt[4] == 0 && cnt[5] == 0 &&
	       cnt[6] == 0 && cnt[7] == 0 && cnt[8] == 0 && cnt[9] == 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i ++) if('0' <= s[i] && s[i] <= '9') cnt[s[i] - 48] ++;
	if(check())
	{
		cout << 0;
		return 0;
	}
	for(int i = 9;i >= 0;i --) for(int j = 1;j <= cnt[i];j ++) cout << i;
	return 0;
}
