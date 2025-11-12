#include <bits/stdc++.h>
#define _loopc(i, a, b) for(int i = (a); i <= (b); i ++)
#define _loopo(i, a, b) for(int i = (a); i <  (b); i ++)
#define _rloopc(i, a, b) for(int i = (a); i >= (b); i --)
#define _rloopo(i, a, b) for(int i = (a); i >  (b); i --)
using namespace std;

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k; cin >> n >> k; //	给一个非负整数 k
	vector<int> A(n + 1);
	_loopc(i, 1, n)
	cin >> A[i];  // 有一个长为 n 的非负整数序列 a1, a2, . . . , an
	
	vector<int> Pre(n + 1); // 异或前缀和
	_loopc(i, 1, n)
	Pre[i] = (Pre[i - 1] ^ A[i]);
	
	//	一个区间 [l, r] 的权值为 al~ar 的二进制按位异或和
	
	//	选择序列中尽可能多的不相交的区间
	int ans = 0;
	for(int l = 1, r = 1; l <= r and r <= n;){
		// S⊕ = Prer ⊕ Prel - 1
		while(r <= n and (Pre[r] ^ Pre[l - 1]) != k) // 找出目标区间 1.靠左 2.短 3. S⊕ == k
			r ++;
		
		if(r > n)	l ++; // 没找到
		else l = r + 1, ans ++; // 找到 更新 ans
		
		r = l;  // 更新 r
	}
	
	//	求出能选出区间数量最大值。
	cout << ans;
	return 0;
}