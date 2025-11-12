#include <bits/stdc++.h>
using namespace std;
int a[2025];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(auto c:s)
		if(c>='0' && c<='9') a[c-'0']++;
	for(int i=9; i>-1; i--)
		for(int j=a[i]; j>0; j--) cout<<i;
	return 0;
}
//不要爆零
//旁边的小孩哥光污染我怎么办qwq 玩记事本的行为已经持续20min了！ 
//感冒了去管老师要纸巾啊为什么要甩键盘上。 
//为什么有一等了还要考j  为什么有一等了还要考j 为什么有一等了还要考j 为什么有一等了还要考j 为什么有一等了还要考j 为什么有一等了还要考j 为什么有一等了还要考j 为什么有一等了还要考j 
//真是闲的 
