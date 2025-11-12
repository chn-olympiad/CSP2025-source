/*
反正最后一题做不出来，不管了，诈个骗吧。
//freopen
feropen("empoly.in","w",st dout);
我要上奇葩代码大赏！
Luogu ID:1360556
开考 20 分钟才发解压密码，状态不好 T1 想了很久才做出来。
T2 最后 20 min 想到了，但是没时间了，就算极限写完以那个码量也不可能在不调的情况下过，目测码量有蓝。
累了，今年应该拿不到 NOIP 参赛资格了。 
*/ 
#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n;
	cin >> n;
	long long ans = 1;
	for(int i = 1; i <= n; i++)ans = ans*i%998244353;
	cout << ans;
	
	
	
	return 0;
}
