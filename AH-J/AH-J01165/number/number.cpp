#include <bits/stdc++.h>
#include <vector>
using namespace std;
int flag = 0, k = 0;
string num;
string nums;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> nums;
    for (int i = 0; i < int(nums.size()); i++){
        flag = toascii(nums[i]);
        if (48 <= flag && flag <= 57){
			num[int(flag) - 48] += 1;
		}
    }
    for (int j = 9; j >= 0; j--){
		for (int k = 0; k < num[j] ; k++){
			cout << j;
		}
	}
    
    
    
    return 0;
}
