#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n , k; 
int a[N] , mark[N];
int ans;
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" . stdout);
	cin >> n >> k;
	int is_A = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(a[i] != 1) is_A = 1;
	}
	if(is_A == 0 && k == 0){
		return cout << n / 2 , 0;
	}
	for(int i = 1 ; i <= n ; i++){//枚举区间长度 
		for(int j = 1 ; j <= n - i + 1 ; j++){//枚举起点 
			int sum = 0;
			bool flag = 0;
			for(int k = j ; k <= j + i - 1 ; k++){//遍历区间 
				if(mark[k] == 1) flag = 1; 
				if(mark[k] == 1 || flag == 1) continue;
				sum ^= a[k];
			}
			if(!flag){
				if(sum == k){
					ans++;
					for(int k = j ; k <= j + i - 1 ; k++) mark[k] = 1;
//					cout << j << " " << j + i - 1 << "\n";
				}
			}
		}
	}
	cout << ans;
	return 0;
} 
//60pts
