// 60'baoli
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int p[500010][21];
int kp[21];
int n,k;
int a[500010];
void init(){
	rep(i,0,20){
		kp[i] = k >> i & 1;
	}
	rep(i,1,n){
		int temp = a[i];
		rep(j,0,20){
			p[i][j] = p[i-1][j];
			p[i][j] += temp & 1;
			temp >>= 1;
			p[i][j] &= 1;
		}
	}
}
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
//	rep(i,1,n) cin >> a[i];
	
	rep(i,1,n) scanf("%d",&a[i]);
	init();
//	rep(i,1,n){
//		rep(j,0,3){
//			printf("%d ",p[i][j]);
//		}
//		printf("\n");
//	}
	int left = 1;
	int right = 1;
	while (right <= n){
		// left ~ right
			rep(tl,left,right){
				bool tlflag = 1;
				rep(w,0,20){
					if (p[right][w] ^ p[tl-1][w] != kp[w]){
						tlflag = 0;
						break;
					}
				}
				if (tlflag){
					ans++;
					left = right + 1;
					break;
				}
			}
			right++;
	}
	cout << ans;
	return 0;
}

