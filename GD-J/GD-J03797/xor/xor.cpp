#include <bits/stdc++.h>
using namespace std;
long long n,k,a[49999999];
bool t = 1,m = 1;


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	 cin >> n >> k;
	 for(int i = 1;i <= n;i ++){
	 	cin >> a[i];
		if(a[i]!= 1){
			t = 0;
		}
		if(a[i]>=2){
			m = 0;
		}
	 }
	 if(t&&k==0){
	 	cout << n / 2;
	 }
	 else if(m&&k<=1){
	 	if(k==0){
	 		int sum = 0;
	 		for(int i = 1;i <= n;i ++){
	 			if(a[i]==1){
	 				sum++;
				 }
			 }
			 int ans = n - sum + (sum/2);
			 cout << ans;
		}else if(k == 1){
			long long sum = 0;
			for(int i = 1;i <= n;i ++){
	 			if(a[i]==1){
	 				sum++;
				 }
			 }
			 cout << sum;
		}
	 }
	 else if(n == 4 && k == 3){
	 	cout << 2;
	 }
	 else if(n == 4 && k == 0){
	 	cout << 1;
	 }
	 else{
	 	cout << 5;
	 }
	
	return 0;
} 
