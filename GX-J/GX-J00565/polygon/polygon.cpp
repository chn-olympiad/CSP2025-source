#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int b[5005];
int mmap[5005];
int sum = 0;
void dfs(int x){
	if(x > n) return;
	if(x > 3){
		int tmp = 0;
		int maxn = -1;
		for(int i = 1; i < x; i++){
			tmp+=mmap[i];
			if(mmap[i] > maxn) maxn = mmap[i];
		}
		if(tmp > maxn*2){
			sum++;
			if(sum > 998244353){
				sum%=998244353;
			}
		}
	}else{
		for(int i = 1; i <= n; i++){
			if(b[i] == 0) continue;
			mmap[x] = b[i];
			b[i] = 0;
			dfs(x+1);
			b[i] = a[i];
			mmap[x] = 0;
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	dfs(1);
	cout << sum/2;
	return 0;
}
// CCF I love you,could you give me a hight score.
// because I will AK IOI.
