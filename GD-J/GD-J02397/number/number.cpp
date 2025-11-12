# include <bits/stdc++.h>
using namespace std;

int cnt[15],n;
string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n = s.size();
	for (int i = 0;i < n;i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnt[(s[i]-'0')] ++;
		}
	}
	for (int i = 9;i >= 0;i --) {
		for (int j = 1;j <= cnt[i];j ++) cout << i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//99998888887777766666655555544444433332111000000000
//99998888887777766666655555544444433332111000000000
