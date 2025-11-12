#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
inline LL read(){
	LL num = 0,sign = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') sign = ch == '-' ? -1 : 1,ch = getchar();
	while (ch >= '0' && ch <= '9') num = (num << 3) + (num << 1) + ch - '0',ch = getchar();
	return sign > 0 ? num : -num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	T = read();
	while (T--){
		int n,a[100010],b[100010],c[100010],maxn[100010],ax[100010],bx[100010],cx[100010],ans = 0;
		int a1 = 0,b1 = 0,c1 = 0;
		n = read();
		for (int i = 1; i <= n; i ++){
			a[i] = read(),b[i] = read(),c[i] = read();
			if (a[i] >= b[i] && a[i] >= c[i]){
				ans += a[i];
				a1 ++;
				maxn[i] = 1,bx[i] = a[i]-b[i],cx[i] = a[i]-c[i];
			} else if (b[i] >= a[i] && b[i] >= c[i]){
				ans += b[i];
				b1 ++;
				maxn[i] = 2,ax[i] = b[i]-a[i],cx[i] = b[i]-c[i];
			} else {
				ans += c[i];
				c1 ++;
				maxn[i] = 3,ax[i] = c[i]-a[i],bx[i] = c[i]-b[i];
			}
		}
		if (a1 > n/2){
			while (a1 > n/2){
				LL minn = 1e9,pos = -1;
				for (int i = 1; i <= n; i ++){
					if (maxn[i] != 1) continue;
					if (bx[i] < cx[i]){
						if (minn > bx[i]){
							minn = bx[i],pos = i;
						} 
					} else{
						if (minn > cx[i]){
							minn = cx[i],pos = i;
						} 
					}
				}
				ans -= minn;
				a1--;
				maxn[pos] = 2;
			}
		}
		if (b1 > n/2){
			while (b1 > n/2){
				LL minn = 1e9,pos = -1;
				for (int i = 1; i <= n; i ++){
					if (maxn[i] != 2) continue;
					if (ax[i] < cx[i]){
						if (minn > ax[i]){
							minn = ax[i],pos = i;
						} 
					} else{
						if (minn > cx[i]){
							minn = cx[i],pos = i;
						} 
					}
				}
				ans -= minn;
				b1--;
				maxn[pos] = 3;
			}
		}
		if (c1 > n/2){
			while (c1 > n/2){
				LL minn = 1e9,pos = -1;
				for (int i = 1; i <= n; i ++){
					if (maxn[i] != 3) continue;
					if (ax[i] < bx[i]){
						if (minn > ax[i]){
							minn = ax[i],pos = i;
						} 
					} else{
						if (minn > bx[i]){
							minn = bx[i],pos = i;
						} 
					}
				}
				ans -= minn;
				c1--;
				maxn[pos] = 1;
			}
		}
		cout << ans << "\n";
	}
}
