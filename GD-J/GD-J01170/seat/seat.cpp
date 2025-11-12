#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m;
LL a[1000];
LL r;
LL cnt;

bool cmp(LL x, LL y){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin >> n >> m;
	for(LL i = 1;i <= n * m;i++){
		cin >> a[i];
		if(i == 1) r = a[i];
	}
	sort(a + 1, a + 1 + n * m, cmp);

	// 开始遍历
	// 第 j 列
	for(LL j = 1;j <= m;j++){
		// 如果 j 是基数，代表行数从 1 到 n
		if(j % 2){
			// 遍历行数
			for(LL i = 1;i <= n;i++){
				cnt++;
				// 判断是否是小 R
				if(a[cnt] == r){
					// 输出结果, return 0;
					cout << j << ' ' << i;
					fclose(stdin);
					fclose(stdout);
					return 0;
				} 
			}
		} 
		// 如果 j 是偶数，代表行数从 n 到 1
		else{
			// 遍历行数
			for(LL i = n;i >= 1;i--){
				cnt++;
				// 判断是否是小 R
				if(a[cnt] == r){
					// 输出结果, return 0;
					cout << j << ' ' << i;
					fclose(stdin);
					fclose(stdout);
					return 0;
				} 
			}
		}
	} 
	
	 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

