#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 +10;
int n, k, arr[N];
bool type1 = true, type0 = true;
int Next[N];
set <int> e[N];
int dp[N];
struct node{
	int data;
}tree[N << 2];

int read(){
	int x = 0, y = 1;
	char ch = getchar();
	while(ch < '0'|| ch > '9'){
		if( ch == '-') y = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

void build(int rot, int l, int r){
	if(l == r){
		tree[rot].data = arr[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(rot << 1, l, mid);
	build(rot <<1 | 1, mid + 1, r);
	tree[rot].data = (tree[rot << 1].data ^ tree[rot << 1 | 1].data);
	return ;
}

int query(int rot, int l, int r, int ql, int qr){
	if(ql > r || qr < l) return 0;
	if(ql <= l && qr >= r){
		return tree[rot].data;
	}
	int ans = 0;
	int mid = (l + r) >> 1;
	if(ql <= mid){
		ans ^= query(rot <<1, l, mid, ql, qr);
	}
	if(qr > mid){
		ans ^= query(rot <<1 | 1, mid + 1, r, ql, qr);
	}
	return ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n = read();
	k = read();
	for(int i = 1; i <= n; i++){
		arr[i] = read();
		if(arr[i] != 1) type1 = false;
		if(arr[i] != 1 && arr[i] != 0) type0 = false;
	}
	if(type1 && k == 0){
		cout << n / 2 << endl;
		return 0;
	} else if(type0 && k <= 1){
		if(k == 0){
			int ans = 0;
			int i = 1;
			while(i <= n){
				if(arr[i] == 0){
					ans++;
				}
				else if(arr[i] == 1){
					if(i < n && arr[i + 1] == 1){
						ans++;
						i = i + 1;
					}
				}
				i++;
			}
			cout << ans << endl;
		} else if(k == 1){
			int ans = 0;
			for(int i = 1; i <= n; i++){
				if(arr[i]){
					ans++;
				}
			}
			cout << ans << endl;
		}
		return 0;
	}
	
	build(1, 1, n);
	
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(query(1, 1, n, i, j) == k){
				Next[i] = j;
				e[j].insert(i);
				break;
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 0; j < e[i].size(); j++){
//			 cout <<e[i][j] << " - " << i << endl;
//		}
//	}
	set <int> :: iterator it;
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i - 1];
		for(it = e[i].begin(); it != e[i].end(); it++){
			dp[i] = max(dp[i], dp[(*it) - 1] + 1);
		}
//		cout << endl;
	}
	cout << dp[n] << endl;
	return 0;
}
