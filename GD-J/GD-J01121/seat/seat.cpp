#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sum,k,x = 1,y = 1;
int t = 1;
int a[1005];
int b[105][105];
bool cmp(int x, int y){
	return x > y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	sum = n * m;
	for(int i = 1; i <= sum; i++){
		scanf("%lld",&a[i]);
		if(i == 1){
			k = a[i];
		}
	}
	sort(a + 1, a + 1 + sum, cmp);
	for(int i = 1; i <= sum; i++){
		b[x][y] = a[i];
		if(k == a[i]){
			printf("%lld %lld",y,x);
			return 0;
		}
		if(x == n && t == 1){
			y++;
			t = -1;
		} else if(x == 1 && t == -1){
			y++;
			t = 1;
		} else{
			x = x + t;
		}
	}
	return 0;
}

