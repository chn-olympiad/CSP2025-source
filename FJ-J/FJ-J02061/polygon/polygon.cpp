#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5010;
int n,a[N], sum[N], ans = 0;
int f_sum(int l,int r){
	return sum[r]-sum[l-1];
}
int f_max(int l,int r){
	int maxn = -1;
	for(int i = l;i <= r;i++){
		maxn = max(a[i],maxn);
	}
	return maxn;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		sum[i] = sum[i-1]+a[i];	
	}
	for(int i = 1;i <= n;i++){
		if(i+3 <= n){
			for(int j = i+3;j <= n;j++){
				if(f_sum(i,j) > 2*f_max(i,j)){
					ans++;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

