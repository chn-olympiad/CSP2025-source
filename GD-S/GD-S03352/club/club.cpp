#include <bits/stdc++.h>
using namespace std;
long long a[100010][5];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		long long n;
		scanf("%lld", &n);
		int maxn[n/2];
		for(int i = 1;i <= n;i++){
			scanf("%lld", &a[i][1]);
			scanf("%lld", &a[i][2]);
			scanf("%lld", &a[i][3]);
		}
		maxn[1] = -1;
		int num = 1;
		for(int i = 1;i <= n;i++){
			if(a[i][1] > maxn[num]){
				maxn[num] = a[i][1];
			}
			else if(num + 1 <= n / 2){
				num++;
				maxn[num] = a[i][1];
			}
		}
		long long number = 0;
		for(int i = 1;i <= num;i++){
			number += maxn[i];
		}
		printf("%lld", number);
	}
	return 0;
}
