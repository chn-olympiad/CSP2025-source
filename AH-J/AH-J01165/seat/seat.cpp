#include <bits/stdc++.h>
using namespace std;
int c, r, score, nums[100005], c0 = 1, r0 = 1;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> c >> r;
	for (int i = 0; i < c + r; i++) cin >> nums[i];
	score = nums[0];
	for (int j = 1; j <= c + r + 1; j++){
		if (nums[j] > score){
			if (c0 % 2 != 0){
				r0++;
				if(r0 > r){
					r0--;
					c0++;
				}
			}
			else{
				r0--;
				if (r0 == 1){
					c0++;
				}
			}
		}
	}
	cout << c0 << " " << r0;
	return 0;
}
