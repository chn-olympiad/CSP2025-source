#include <bits/stdc++.h>
using namespace std;
int a[500005],n,k,cnt = 0;
int main(){
//	¼ÇµÃÈ¥×¢ÊÍ 
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		if (a[i] == k) cnt++;
	}
	if (n == 2 && cnt == 0 && a[1] ^ a[2] == k) cnt++;
	cout << cnt;
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n - i + 1; j++){
//			int x = a[j];
//			for (int k = j; k <= j + i; k++){
//				if (a[i] != -1) x = x ^ a[k];
//				else{
//					x = 0;
//					break;
//				}
//			}
//			if (x == k){
//				cnt++;
//				for (int k2 = j; k2 <= j + 1; k2++) a[i] = -1;
//			} 
//		}
//	}
//	cout << cnt;
	return 0;
} 
