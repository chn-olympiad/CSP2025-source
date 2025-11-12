#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char s[1000001];
	cin >> s;
	long long int nums[100001]; //存储数字
	int n = 1;
	for(int i = 0; i <= strlen(s); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			nums[n++] = s[i] - '0'; //转化为数字 
		}
	} 
	sort(nums + 1, nums + n + 1, cmp);
	for(int i = 1; i < n; i++){
		cout << nums[i];
	}
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}