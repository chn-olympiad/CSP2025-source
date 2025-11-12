#include <bits/stdc++.h>
using namespace std;
int n, k ,nums[100005], ans = 0, ans_last = 0, marki[100005], markj[100005], point = 0;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	for (int i = 0; i < n; i++){
		ans = 0 | (nums[i] & nums[i]);
		if (nums[i] != k && ans == k && marki[i] == 0 && markj[i] == 0){
			ans_last++;
			marki[i]++;
			markj[i]++;
			continue;
		}
		for (int j = i + 1; j < n; j++){
			if (j - i == 1){
				if (marki[i] == 0 && markj[j] == 0){
					ans = 0 | (nums[i] & nums[j]);
					marki[i]++;
					markj[j]++;
				}
			}
			else{
				ans = nums[i];
				point = i;
				for (int l = i; l <= j; l++){
					if ((marki[point] == 0 && markj[l] == 0) || (marki[l] == 0 && markj[point] == 0)){
						ans = 0 | (ans & nums[l]);
					}
					else{
						break;
					}
					marki[point] = 1;
					markj[l] = 1;
					point++;
				}
			}
			if (ans == k && ans != nums[i]){
				ans_last++;
				break;
			}
		}
		
	}
	cout << ans_last;
	return 0;
}
