#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin>>str;
	int len = str.size(),cnt = 0;
	vector<int> nums(len);
	for(int i = 0;i < len;i++){
		if(str[i] >= '0' && str[i] <= '9'){
			nums[cnt] = str[i] - 48;
			cnt++;
		}
	}
	sort(nums.begin(),nums.end());
	for(int i = len - 1;i >= len - cnt;i--){
		cout<<nums[i];
	}
	return 0;
}
