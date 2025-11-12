#include<bits/stdc++.h>
using namespace std;

int n,a[5010],ans1;
const int N = 998244353;

void dfs(int x,int y,int ma,int cnt){
	if(x == n + 1){
		if(ma * 2 < y && cnt >= 3){
			ans1++;
		}
		return;
	}
	dfs(x + 1,y,ma,cnt);
	dfs(x + 1,y + a[x],max(ma,a[x]),cnt + 1);
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int ok = 1;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(a[i] != 1){
			ok = 0;
		}
	}
	if(ok){
		long long ans = 1;
		int t = n;
		while(t--){
			ans *= 2;
			ans %= N;
		}
		long long k = n * (n - 1) / 2;
		k %= N;
		ans -= k;
		ans -= n;
		ans--;
		printf("%lld",ans);
		return 0;
	}
	dfs(1,0,0,0);
	printf("%lld",ans1);
	return 0;
}