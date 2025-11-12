#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n, k;
LL a[1000100];
LL sum[1000100];
LL final_ans = 0;
LL YiHuo(LL a, LL b){ 
	LL ans = 0;
	LL multiplier = 1;
	while(a != 0 || b != 0){
		if(a % 2 != b % 2){
			ans = ans + multiplier;
		}
		multiplier *= 2;
		a /= 2;
		b /= 2;
	}
	return ans;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	memset(a, 0, sizeof a);
	memset(sum, 0, sizeof sum);
	for(LL i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = YiHuo(sum[i - 1], a[i]);
	}
	LL lstr = 0;
	for(LL i = 1; i <= n; i++){
		LL ast = YiHuo(sum[i], k);
		LL l = lstr + 1, r = i + 1;
		while(l + 1 < r){
			LL mid = (l + r) / 2;
			if(sum[mid] <= ast)l = mid;
			else r = mid;
		}
		
		if(sum[l - 1] == ast){
			final_ans++;
			lstr = i;
		}
	}
	cout << final_ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
