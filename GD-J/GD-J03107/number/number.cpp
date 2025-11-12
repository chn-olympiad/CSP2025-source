#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010], num;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0, n = s.size(); i < n; i ++)
		if (s[i] >= '0' && s[i] <= '9')a[++ num] = s[i] ^ 48;
	sort(a + 1, a + num + 1, greater<int> ());
	if (!a[1]){
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= num; i ++)cout << a[i];
	return 0;
}
/*
花褪残红青杏小，燕子飞时，绿水人家绕。枝上柳绵吹又少，天涯何处无芳草。 
墙里秋千墙外道，墙外行人，墙里佳人笑。笑渐不闻声渐悄，多情却被无情恼。 
*/
