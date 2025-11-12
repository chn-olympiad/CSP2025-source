#include<iostream>
#include<cstdio>
using namespace std;

int n;
int a[5010];
int nums[5010];

int main(){
	freopen("polygon.in", "r", "stdin");
	freopen("polygon.out", "w", "stdout");
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	nums[1] = 1;
	for(int i=1; i<=n; i++){
		nums[i] = nums[i-1]+((i+1)*i/2);
	}
	cout << nums[n-2]%998244353;
	return 0;
} 
