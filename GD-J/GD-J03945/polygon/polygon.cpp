#include<bits/stdc++.h>
using namespace std;
int n,a[6000],b = 1,p = 998244353,a1,k,d;
long long ans,c;
long long po(long long a2,long long b2){
	long long rep = 1;
	while(b2){
		if(b2 & 1){
			rep *= a2;
			rep %= p;
		}
		a2 *= a2;
		a2 %= p;
		b2 >>= 1;
	}
	return rep;
}
long long dfs(long long x,long long cnt,long long t){
	if(cnt >= k){
		return po(2,n - x - 1);
	}
	if(x == t){
		return 0;
	}
	d = cnt;
	cnt += dfs(x + 1,cnt,t);
	cnt += a[x];
	cnt += dfs(x + 1,cnt,t);
	cnt -= a[x];
	cnt %= p;
	return cnt - d;
}
int main(){
	freopen("polygon2.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d" ,&n);
	for(int i = 1;i <= n;i++){
		scanf("%d" ,&a[i]);
		if(a[i] > 1){
			b = 0;
		}
	}
	if(b == 1){
		for(int i = 1;i <= n;i++){
			if(a[i] == 1){
				a1++;
			}
		}
		printf("%lld" ,(((a1 - 1) * (a1 - 1) - a1 - 1) / 2) * a1 + po(2,(long long)(n - a1)));
	}else{
		//sort(a + 1,a + n + 1);
		for(long long i = n;i >= 1;i--){
			k = a[i] * 2;
			c = dfs((long long)1,(long long)0,i);
			if(c == 0){
				printf("%lld" ,ans);
				return 0;
			}
			ans += c;
			ans %= p;
		}
	}
	return 0;
}
