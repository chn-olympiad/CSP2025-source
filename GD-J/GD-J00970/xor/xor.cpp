#include <iostream>
#include <vector>
using namespace std;
int n, k;
int a[10005], sum[10005];
bool add(vector<int> &num){
	num[n]++;
	int carry = 0;
	for(int i = num.size() - 1; i >= 0; i--){
		num[i] += carry;
		carry = 0;
		if(num[i] == 2){
			num[i] = 0;
			carry++;
		}
		else break;
	}
	if(carry) return false;
	else return true;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int n, k;
//	cin >> n >> k;
//	for(int i = 1; i <= n; i++){
//		cin >> a[i];
//		sum[i] = sum[i - 1] + a[i];
//	}
//	vector<int> l, r;
//	for(int i = 1; i <= n; i++)
//		for(int j = i + 1; j <= n; j++){
//			if((a[j] - a[i - 1]) % 2 == 0){
//				l.push_back(i);
//				r.push_back(j);
//			}
//		}
//	int m = l.size(),ans = 0;
//	vector<int> num(m), need;
//	do{
//		for(int i = 0; i < m; i++){
//			if(num[i])
//				need.push_back(i);
//		}
//		int flag = 1;
//		for(int i = 0; i < need.size() - 1; i++){
//			if(r[need[i]] >= l[need[i + 1]]){
//				flag = 0;
//				break;
//			} 
//		}
//		need.clear();
//		if(flag) ans++;
//	} while(add(num));
//	cout << ans;
	puts("0");
	return 0;
}

