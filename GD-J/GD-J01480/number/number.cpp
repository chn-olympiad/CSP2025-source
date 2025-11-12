#include <bits/stdc++.h>

std::string str;
int ans[1000010], cnt;

int main() {
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout); 
	std::cin >> str;
	for (int i = 0; i < str.size(); i ++) 
		if (str[i] >= '0' && str[i] <= '9') ans[++ cnt] = str[i] - '0';
	std::sort(ans + 1, ans + cnt + 1);
	for (int i = cnt; i >= 1; i --) std::cout << ans[i];
	return 0;
}
/*
luogu uid 1047636
score = 100 + 100 + 100 + 80 = 380
ÄÑ¶È = ºì ºì »Æ ÂÌ 
*/
