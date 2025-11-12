#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int nums[n];
	for(int i = 0;i<n;++i) cin >> nums[i]; 
	cout << n-k+2;
}
