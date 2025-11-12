#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int t , n , la , lb , lc;
int a[N] , b[N] , c[N];
long long ans;
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	scanf("%d" , &t);
	while(t--){
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; ++i){
			int num[5];
			scanf("%d%d%d" , &num[1] , &num[2] , &num[3]);
			int x = max(max(num[1] , num[2]) , num[3]) , y = -1;
			for(int i = 1 ; i <= 3 ; ++i)
				if(num[i] > y && num[i] != x)
					y = num[i];
			if(y == -1)
				y = x;
			if(x == num[1])
				a[++la] = x - y;
			else if(x == num[2])
				b[++lb] = x - y;
			else
				c[++lc] = x - y;
			ans += x;
		}
		if(la > n / 2){
			sort(a + 1 , a + la + 1);
			for(int i = 1 ; la > n / 2 ; ++i)
				ans -= a[i] , la -= 1;
		}
		else if(lb > n / 2){
			sort(b + 1 , b + lb + 1);
			for(int i = 1 ; lb > n / 2 ; ++i)
				ans -= b[i] , lb -= 1;
		}
		else if(lc > n / 2){
			sort(c + 1 , c + lc + 1);
			for(int i = 1 ; lc > n / 2 ; ++i)
				ans -= c[i] , lc -= 1;
		}
		printf("%lld\n" , ans);
		ans = 0 , la = 0 , lb = 0 , lc = 0;
	}
	return 0;
}
