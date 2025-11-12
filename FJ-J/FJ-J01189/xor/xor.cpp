#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}
inline void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
	return;
}
struct datas{
	int l,r;
}a[1000005];
int n, m, ac[100005], ak[100005], ans,cnt;
bool w[1000005];
bool cmp(datas x,datas y){
	if(x.r-x.l==y.r-y.l) return x.l<y.l;
	return x.r-x.l<y.r-y.l;
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n = read();
	m = read();
	for (int i = 1; i <= n; i++) {
		ac[i] = read();
		ak[i] = ak[i - 1] ^ ac[i];
	}
	if(n==2){
		if(ac[1]==m) ans++;
		if(ac[2]==m) ans++;
		if(ac[1]^ac[2]==m) ans++;
		write(ans);
		return 0;
	}
//	for (int i = 1; i <= n; i++) write(ak[i]);
//	printf("\n");
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n-j+1; i++) {
			int l = i - 1, r = i + j - 1;
			if (abs(ak[r] - ak[l]) == m) {
				ans++;
				a[ans].l=l+1;
				a[ans].r=r;
			}
		}
	}
	sort(a+1,a+ans+1,cmp);
//	for(int i=1;i<=ans;i++){
//		write(a[i].l);
//		printf(" ");
//		write(a[i].r);
//		printf("\n");
//	}
	for(int i=1;i<=ans;i++){
		bool pd=true;
		for(int j=a[i].l;j<=a[i].r;j++){
			if(w[j]==1){
				pd=false;
				break;
			}
		}
		if(pd){
			for(int j=a[i].l;j<=a[i].r;j++)w[j]=1;
			cnt++;
		}
	}
	write(cnt);
	return 0;
}
/*
我终将青春还给了他
也从指尖弹出的盛夏
心之所动
且就随风去吧
逆着光行走
任风吹雨打

我喜欢你wyt
*/
