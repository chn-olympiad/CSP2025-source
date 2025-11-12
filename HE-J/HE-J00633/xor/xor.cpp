#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
/*
异或规则：
若0和1，则为1；否则为0
任意数和0异或都等于它本身
*/
int n, k, a[maxn]; 
int r[maxn];
int mist = 0;
bool vis[maxn];

//x是当前下标，tot是前几个数进行异或和后的数值，mi是当前的最大值 
void search(int x, int tot, int mi){
	if (x == n){
		mist = max(mist, mi);
		return;
	}
	for (int i = x;i <= n;++i){
		if (!vis[i]){
			vis[i] = 1;
			if (a[i] xor tot == k){
				mi++;
				tot = 0;
			} 
			else tot = a[i] xor tot;
			search(i, tot, mi);
			vis[i] = 0;
		}
	}
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1;i <= n;++i){
		cin >> a[i];
	}
	
	//特判 
	if (n == 1){
		if (a[1] != k)
			cout << 0;
		else cout << 1;
		return 0;
	} 
	if (n == 2){
		if (a[1] xor a[2] == k)
			cout << 1;
		else if (a[1] == a[2] == k)
			cout << 2;
		else cout << 0;
		return 0;
	}
	
	if (k == 0){
		int e[maxn], mmm = 0;
		for (int i = 1;i <= n;++i){
			e[a[i]]++;
		}
		for (int i = 1;i <= n;++i){
			if (e[i] > 1) mmm++;
		}
		cout << mmm;
		return 0;
	} 
	
	search(1, 0, 0);
	
	cout << mist-1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
