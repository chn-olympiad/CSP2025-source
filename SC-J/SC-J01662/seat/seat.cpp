#include<bits/stdc++.h>
using namespace std;
int n , m , ans = 0 , Ans = 0;
int a[105];
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	int id = 0;
	for(int i = 1 ; i <= n * m ; i++){
		scanf("%d" , &a[i]);
		if(i == 1)id = a[i];
	}
	sort(a + 1 , a + 1 + n * m , greater<int>());
	for(int i = 1 ; i <= n * m ; i++){
		if(a[i] == id){
			ans = (i + n - 1) / n;
			if(ans % 2 == 1){
				if(i % n != 0)Ans = i % n;
				else Ans = n;
			}else{
				Ans = n - i % n + 1;
			}
			break;
		}
	}
	printf("%d %d" , ans , Ans);
	return 0;
}