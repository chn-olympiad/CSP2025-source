#include<bits/stdc++.h>
using namespace std;

int n, maxNum=INT_MIN, cnt=0;
int nums[5005];

bool Check(int a, int b);

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "r", stdout);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> nums[i];
		maxNum = max(maxNum, nums[i]);
	}
	for(int i = 0; i < n-2; i++){
		for(int j = 3; j <= n; j++){
			cnt += Check(i, j);
		} 
	}
	
	cout << cnt;

	fclose(stdin);
	fclose(stdout);
	return 0;
}

bool Check(int a, int b){
	int sum=0;
	for(int k = a; k < b; k++)
		sum += nums[k];
	if(sum > maxNum*2)
		return 1;
	return 0;
}
