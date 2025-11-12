#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n,k;
LL a[5000010];
LL num[5000010];
LL ans;
bool flag1 = 1; // 特殊性质 1 
bool flag2 = 1; // 特殊性质 2 
bool flag3 = 1; // 特殊性质 3 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k >> a[1];
	num[1] = a[1];
	for(LL i = 2;i <= n;i++){
		LL x;
		cin >> x;
		num[i] = x;
		if(x != 1) flag1 = 0;
		if(x != 1 && x != 0) flag2 = 0;
		if(x > 255) flag3 = 0;
		a[i] = x ^ a[i - 1];
		
	}
	if(flag1){
		cout << n;
	} else if(flag2){
		LL last = 0;
		for(LL i = 1;i <= n;i++){
			if(!last){
				if(a[i] == k){
					last = i;
					ans++;
				}
			} else {
				if( (a[i] ^ a[last]) == k ){
					last = i;
					ans++;
				}
			}
		}
		cout << ans;
	} else if(flag3){
		for(LL j = 0;j < n;j++){
			LL start = 1;
			LL cnt = 0, i = 0;
			while(i <= n){
				i++;
				if(num[i] == -1){
					cnt = 0;
					start = i + 1;
					continue;
				}
				cnt++;
				if(cnt == j + 1){
					break;
				}
			}
			for(LL i = start;i <= n - j;i++){
				if(num[i + j] == -1){
					LL tmp_start = i + j,tmp_cnt = 0,tmp_i = i + j - 1;
					while(tmp_i <= n){
						tmp_i++;
						if(num[tmp_i] == -1){
							tmp_cnt = 0;
							tmp_start = tmp_i + 1;
							continue;
						}
						tmp_cnt++;
						if(tmp_cnt == j + 1){
							break;
						}
					}
					if(tmp_start > n - j) break;
					else i = tmp_start;
					continue;
				}
				if( (a[i - 1] ^ a[i + j]) == k){
					
					for(LL g = i;g <= i + j;g++) num[g] = -1;
					
					ans++;
					LL tmp_start = i + j,tmp_cnt = 0,tmp_i = i + j - 1;
					while(tmp_i <= n){
						tmp_i++;
						if(num[tmp_i] == -1){
							tmp_cnt = 0;
							tmp_start = tmp_i + 1;
							continue;
						}
						tmp_cnt++;
						if(tmp_cnt == j + 1){
							break;
						}
					}
					if(tmp_start > n - j) break;
					else i = tmp_start;
				}
			}
		}
		
//		for(LL i = 1;i <= n;i++){
//			if(num[i] == k) num[i] = -1,ans++;
//		}
//		for(LL i = 1;i < n;i++){
//			if(num[i + 1] == -1){
//				i = i + 1;
//			}
//			if( (num[i] ^ num[i + 1]) == k) num[i] = -1,num[i + 1] = -1, ans++;
//		}
//		LL last = 0;
//		for(LL i = 1;i <= n;i++){
//			if(num[i] == -1){
//				last = i;
//				continue;
//			}
//			if( (a[i] ^ a[last]) == k){
//				last = i;
//				ans++;
//			}
//		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

