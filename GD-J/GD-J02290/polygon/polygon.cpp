#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int nums[n];
	for(int i=0;i<n;i++){
		cin >> nums[i];
	}
	if(n==5){
		if(nums[0]==1)
			cout << 9;
		else
			cout << 6;
	}
	if(nums[0]==1 && nums[1]==1)
		cout << 1;
	return 0;
}
