#include <bits/stdc++.h>
using namespace std;
const int nn = 1e5 + 5;
struct s{
	int x , y , z , count; 
	bool f1 = true , f2 = true , f3 = true;
}a[nn];
bool cmp(s x , s y){
	return x.x > y.x;
}
bool cmp1(s x , s y){
	return x.count > y.count;
}
bool cmp2(s x , s y){
	if(x.x == y.x && x.y == y.y) return x.z > y.z;
	else if(x.x == y.x) return x.y > y.y;
	else return x.z > y.z;
}
int main (){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	long long t;
	scanf("%lld" , &t);
	while(t --){
		long long n , ans  = 0, cnt = 0;
		scanf("%lld" , &n);
		long long k = n / 2;
		for(long long i = 1;i <= n;i ++){
			scanf("%lld%lld%lld" , &a[i].x , &a[i].y , &a[i].z);
			if(a[i].y == 0) ans ++;
			if(a[i].z == 0)	cnt ++;
			a[i].count = a[i].x + a[i].y + a[i].z;
		}
		if(ans == n && cnt == n){
			long long sum = 0;
			sort(a + 1 , a + n + 1 , cmp);
			for(long long i = 1;i <= k;i ++){
				sum += a[i].x;
			}
		    printf("%lld\n" , sum);	
		}else if(cnt == n ){
			long long sum =0 , ans1 = 0 , ans2 = 0;
			sort(a + 1 , a + n  + 1 , cmp1);
			for(long long i = 1;i <= k;i ++){
				if(a[i].x > a[i].y && a[i].f1 == true){
					a[i].f1 = false;
					sum += a[i].x;
					ans1 ++;
				}else{
					a[i].f2 = false;
					sum += a[i].y;
					ans2 ++;
				}
			}
			for(long long i = k + 1;i <= n;i ++){
				if(a[i].f1 == true && ans1 < k){
					sum += a[i].x;
				}else if(a[i].f2 == true && ans2 < k){
					sum += a[i].y;
				}
			}
			printf("%lld\n" , sum);
		}else if(n == 2){
			long long maxa ;
			maxa = max(max(a[1].x , a[1].y) , a[1].z);
			if(maxa == a[1].x){
				maxa += max(a[2].y , a[2].z);
			}else if(maxa == a[1].y){
				maxa += max(a[2].x , a[2].z);
			}else{
				maxa += max(a[2].x , a[2].z);
			}
			long long maxaa ;
			maxaa = max(max(a[2].x , a[2].y) , a[2].z);
			if(maxaa == a[2].x){
				maxaa += max(a[1].y , a[1].z);
			}else if(maxaa == a[1].y){
				maxaa += max(a[1].x , a[1].z);
			}else{
				maxaa += max(a[1].x , a[1].z);
			}
			printf("%lld\n" , max(maxaa , maxa));
		}else{
			sort(a + 1 , a + n + 1 , cmp2);
			long long sum = 0 , fun1 = 0 , fun2 = 0;
			for(long long i = 1;i <= n;i ++){
				long long maxa;
				maxa = max(max(a[i].x , a[i].y) , a[i].z);
				if(maxa == a[i].x && fun1 < k){
					sum += a[i].x;
					fun1 ++;
				}else if(maxa == a[i].y && fun2 < k){
					sum += a[i].y;
					fun2 ++;
				}else{
					sum += a[i].z;
				}
			}
			printf("%lld\n" , sum);
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
