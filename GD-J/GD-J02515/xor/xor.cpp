#include <bits/stdc++.h>
using namespace std;
long long a[100100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,l = 1,big_xor_len = 0;
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	for(int i = 1;i <= n;i++){
		long long xor_ans = a[l];
		if(i == l){
			long long n1 = 1;
			big_xor_len = max(big_xor_len,n1);
		}else{
			for(int j = l + 1;j <= i;j++){
				xor_ans ^= a[j];
				if(xor_ans >= k){
					big_xor_len = max(big_xor_len,i - l);
					l = j;
					break;
				}
			}
		}
	}
	cout << big_xor_len;
	fclose(stdin); 
	fclose(stdout);
	return 0;
} 
