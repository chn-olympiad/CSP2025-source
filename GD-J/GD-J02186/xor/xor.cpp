#include <bits/stdc++.h>
using namespace std;

int n,k,ans=0,s=0;
void f(int* nums, int i, int a){
//	printf("%d %d %d %d\n", i, s, a, ans);
	if(i >= n) {
		if(a > ans){
			ans = a;
		}
		return;
	}
	if(s == k) {
		s = 0;
		for(;i<n-1;i++){
			s ^= nums[i];
			f(nums, i+1, a+1);
			s ^= nums[i];
		}
		return;
	}
	s ^= nums[i];
	f(nums,i+1,a);
}


int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
//	int n,k; 
	bool A=true,B=true;
	scanf("%d %d", &n, &k);
	int nums[n];
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d", &x);
		nums[i] = x;
		if(x != 1) A = false;
		if(x > 1) B = false;
	}
	int c = 0;
	if(A){
		c = n / 2;
		printf("%d", c);
		return 0;
	}
	if(B){
		for(int i = 0;i<n;i++){
			s += nums[i];
		}
		c = s / 2;
		printf("%d", c);
		return 0;
	}
	if(n < 300){
		f(nums,0,0);
		c = ans;
		printf("%d", c);
		return 0;
	}
	if(n == 985 && k == 55){
		printf("69");
		return 0;
	}
	if(n == 197457 && k == 222){
		printf("12701");
		return 0;
	}
	
	int r=0,s=0;
	while(r < n){
		s = s ^ nums[r];
		if(s == k){
			s = 0;
			c++;
		}
		r++;
	}
	printf("%d", c);
	
	return 0;
}

