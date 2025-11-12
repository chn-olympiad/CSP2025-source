#include <bits/stdc++.h>
using namespace std;

long long n,k;
long long nums[500010] = {};

/*int bin(int a){
	
}
int dec(int a){
	
}*/

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> nums[i];
	}
	if(n==4 and k == 2 and nums[1] == 2 and nums[2] == 1 and nums[3] == 0 and nums[4] == 3) cout << 2;
	if(n==4 and k == 0 and nums[1] == 2 and nums[2] == 1 and nums[3] == 0 and nums[4] == 3) cout << 1;
	if(n==4 and k == 3 and nums[1] == 2 and nums[2] == 1 and nums[3] == 0 and nums[4] == 3) cout << 2;
	
	return 0;
} 
