#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 110;
int n,m,s,k;
int a[N],c,r;
inline bool cmp(int a,int b){return a > b;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for ( int i = 1; i <= n * m; i ++){
		scanf("%lld",&a[i]);
	}
	s = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for ( int i = 1; i <= n * m; i ++){
		if (a[i] == s){
			k = i;
			break;
		}
	}
	c = (k + n - 1) / n;
	int q = (k - 1) % n;
	if (c & 1){
		r = q + 1;
	}else r = n - q;
	printf("%lld %lld",c,r);
	return 0;
}
