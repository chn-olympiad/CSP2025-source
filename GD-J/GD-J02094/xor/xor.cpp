#include <bits/stdc++.h>
using namespace std;

int n,k,a[514514],b[514514];
int vis[514514];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vis[k] = 1;
	int res = 0;
	int pre = 0;
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] ^ a[i];
		if (a[i] == k) {
			res++;
			pre = i + 1;
			vis[k] = i;
			b[i] = 0;
			continue;
		}
//		cout << i << " " << b[i] << " " << vis[b[i]] << "\n";
		if (vis[b[i]] != 0 && vis[b[i]] >= pre && vis[b[i]] <= i) {
			res++;
			pre = i + 1;
			vis[k] = i;
			b[i] = 0;
		}
			vis[k ^ b[i]] = i + 1;
//			cout << (k ^ b[i]) << "\n";
	}
	cout << res;
	return 0;
}

//wo chang chang zhui yi guo qu
// luogu uid:723036 
// 11:00: Complete T1,T2,T4 i don't know how to do t3!
// Genshin Impact
// int mian
// feropen
//freopen
// freopen
// while(1) {}
// "#Shang4Shan3Ruo6Shui4" he yi wei?
// 11:08 666 zen me quan bu dou zai wan edge://surf ?
// ping mu qian de xiao peng you men,ni jue de wo neng ba t3 zuo chu lai ma?
// 11:17 mao si T3 shi tan xin, kai shi zuo.
// 11:25 zhui ji le.
// I probably will be showed in "GD CSP mi confusing xing wei big show"  
