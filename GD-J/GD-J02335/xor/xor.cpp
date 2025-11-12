//啊啊啊发现问题时已经来不及了
//不管了这个代码大概能过10~30分 

 #include <iostream>
#include <cstdio>
using namespace std;

int n, k, a[500010];;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int l = 1, r = 1, cur = a[1], cnt = 0;
	while(l <= n && r <= n){
		while(r <= n){
			if (cur == k){
				cnt++;
				l = r + 1;
				r = r + 1;
				cur = a[l];
			}
			else if (cur > k){
				l++;
				cur ^= a[l];
				if (r < l){
					r = l;
					cur = a[l];
				}
			}
			else{
				r++;
				cur ^= a[r];
			}
		}
	}
	cout << cnt;
	
	return 0;
} 
