#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
typedef long long ll;
int a[N];
string num[N];//num[i]表示a[i]的二进制 
int sum[N];//sum[i]表示a[i]的按位和 
ll summ[N];//sum[i]的前缀和 
string change(int t){
	string s;
	while(t){
		s += (char)(t % 2 + '0');
		t /= 2;
	}
	reverse(s.begin() , s.end());
	return s;
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		num[i] = change(a[i]);
	}
	for(int i = 1 ; i <= n ; i ++){
		string s = num[i]; 
		if(s.size() <= 1){
			if(s[0] == '1'){
				sum[i] = 1;
			}else{
				sum[i] = 0;
			} 
		}else{
			for(int j = 0 ; j < s.size() - 1 ; j ++){
				if(s[j] != s[j + 1]){
					sum[i] ++;
				}
				sum[i] += ((int)(s[j] - '0') || (int)(s[j - 1] - '0'));
			}
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		summ[i] = summ[i - 1] + sum[i];
	}	
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = i ; j <= n ; j ++){
			if(summ[j] - summ[i - 1] == k || a[i] == k){
				ans ++;
				i = j;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
//4 2
//2 1 0 3
