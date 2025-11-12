#include <bits/stdc++.h>
using namespace std;
long long read(){
	long long w = 1, r = 0;char ch = getchar();
	while (!isdigit(ch)){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch)){
		r = r * 10 + ch - '0';
		ch = getchar();
	}
	return r * w;
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    // program
    /*
	观察发现，异或和可以做前缀和
	我们便利一遍前缀和数组，每次寻找潜在的0，并记 
	我们证明一下 每次我们找到每一个后面可以匹配到前面的地方（可以证明，MAP的匹配方式可以保证每次找到最短的区间）
	然后我们可以发现，只要区间足够小，可以找到最优吗？
	我们可以发现以下情况：
	1.单独区间，没有被重合的，类似于
	|-----||----|（一个|---|代表一个区间）
	这种情况下我们发现最优的就是选择这个区间
	2.有部分重合，例如：
	|------|
	     |-----|
	这样的重合，我们只能选择一个区间，而在多个区间同时重合的情况下，如：
	|------||-------| |------| 
		  |------| |-----|
	我们发现 选最后一个出现的一定不会更劣 
	然而我们每次都匹配最小区间，一定可以保证先到的先有（更短）
	3.包含关系，例如
	|--------------|
	   |------|
	由于内部区间更小，我们还可以想象一种情况：
	 |--------------|
	|---| |------| |----|
	此时一定是选择小区间更优，每次选择最小区间一定更优 
			        
					  
	*/
	int n, k;
	cin >> n >> k;
	vector<long long> a(n + 5), pre(n + 5, 0);
	for(int i = 0;i < n;i++){
	    a[i] = read();
		pre[i] = pre[i - 1] ^ a[i];
	}
//	cout << "readover"; 
	map<long long, int> m;
	int ans = 0;
	for(int i = n - 1;i >= 0;i--){
		m[pre[i]]++;
		if(m[pre[i - 1] ^ (long long)k]) ans ++, m.clear();
		pre[i] = pre[i + 1] ^ a[i];
	}
	m.clear();
	int ans2 = 0;
	for(int i = 0;i < n;i++){
		m[pre[i]]++;
		if(m[pre[i + 1] ^ (long long)k]) ans2 ++, m.clear();
//		pre[i] = pre[i + 1] ^ a[i];
	}
	cout << max(ans, ans2) << endl;
    return 0;
    // 要对拍一下验证 
}
