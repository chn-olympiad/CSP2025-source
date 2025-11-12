#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N] , b[N] , c[N] , flag[N];
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	scanf("%d" , &t);
	while(t --){
		int n ;
		scanf("%d" , &n);
		memset(a , 0 , sizeof a);
		memset(b , 0 , sizeof b);
		memset(c , 0 , sizeof c);
		memset(flag , 0 , sizeof flag);
		for(int i = 1 ; i <= n ; i ++){
			scanf("%d%d%d" , &a[i] , &b[i] , &c[i]);
		}
		int cnt = 0 , club1 = 0 , club2 = 0 , club3 = 0 , af = 0 , bf = 0 , cf = 0 , af1 = 0 , af2 = 0 , bf1 = 0 , bf2 = 0 , cf1 = 0 , cf2 = 0;
		for(int i = 1 ; i <= n ; i ++){
			if(flag[i] == 0 && a[i] >= b[i] && a[i] >= c[i] && club1 < n / 2) {
				cnt += a[i];
				flag[i] = 1;
				club1 ++;
				af = a[i];
				af1 = b[i];
				af2 = c[i];
			}else if(flag[i] == 0 && (b[i] >= a[i] && b[i] >= c[i] && club2 < n / 2) || (club1 >= n / 2 && club2 < n / 2)) {
				if(af + b[i] < af1 + a[i]){
					cnt -= af + b[i];
					cnt += af1 + a[i];
					club2 --;
				}else if(af + b[i] < af1 + b[i]){
					cnt -= af + b[i];
					cnt += af1 + b[i];
					club2 --;
				}else cnt += b[i];
				flag[i] = 1;
				club2 ++;
				bf = b[i];
				bf1 = a[i];
				bf2 = c[i];
			}else{
				if(bf + c[i] < bf1 + c[i]){
					cnt -= bf + c[i];
					cnt += bf1 + c[i];
					club3 --;
				}else if(bf + c[i] < bf2 + c[i]){
					cnt -= bf + c[i];
					cnt += bf2 + c[i];
					club3 --;
				}else if(bf1 + c[i] < bf2 + c[i]){
					cnt -= bf1 + c[i];
					cnt += bf2 + c[i];
					club3 --;
				}else cnt += c[i];
				flag[i] = 1;
				club3 ++;
				cf = c[i];
				cf1 = a[i];
				cf2 = b[i];
			}
		}
		printf("%d\n" , cnt);
	}
	return 0;
}
