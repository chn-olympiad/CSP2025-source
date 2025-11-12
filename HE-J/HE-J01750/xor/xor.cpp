#include<bits/stdc++.h>
const int N = 1e6 + 5;
int n,a[N],k,cnt;
struct node{
	int l,r;
	bool operator < (node o) const{
		return r < o.r;
	}
}b[N];
bool flag = 1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= n;i ++){
		scanf("%d",a + i);
		flag &= (a[i] <= 1);
	}
	if(flag){
		int cnt_1 = 0,ans = 0;
		if(k == 0){
			for(int i = 1;i <= n;i ++){
				if(a[i]) cnt_1 += 1;
				else{
					ans += cnt_1 / 2 + 1;
					cnt_1 = 0;
				}
			}
			if(cnt_1) ans += cnt_1 / 2;
		}
		cnt_1 = 0;
		for(int i = 1;i <= n;i ++){
			cnt_1 += a[i]; 
		}
		printf("%d\n",std::max(ans,cnt_1 / (2 - k)));
	}
	else if(n <= 1e3){
		int sum_xor = 0;
		for(int i = 1;i <= n;i ++){
			sum_xor = 0;
			for(int j = i;j <= n;j ++){
				sum_xor ^= a[j];
				if(sum_xor == k) {
					b[++ cnt].l = i,b[cnt].r = j;
				}
			}
		}
		std::sort(b + 1,b + cnt + 1);
		int r = 0,ans = 0;
		for(int i = 1;i <= cnt;i ++){
			if(r < b[i].l){
				r = b[i].r;
				ans ++;
			}
		}
		printf("%d\n",ans);
	}
}
