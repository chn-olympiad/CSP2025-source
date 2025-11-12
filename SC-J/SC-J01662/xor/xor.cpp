#include<bits/stdc++.h>
using namespace std;
int a[200005] , cnt[10];
int n , k;
void solve1(){
	if(n == 2){
		printf("1");
	}else{
		int ans = n / 2;
		printf("%d" , ans);
	}
	return ;
}
void solve2(){
	int ans = 0;
	for(int i = 1 ; i <= n ;){
		while(true){
			if(a[i] == 1){
				ans++;
				i++;
				break;
			}else{
				i++;
			}
		}
	}
	printf("%d" , ans);
}
void solve3(){
	int ans = 0;
	for(int i = 1 ; i <= n ; ){
		int cnt = 0 , Cnt = 0;
		while(true){
			if(a[i] == 0)cnt++;
			else Cnt++;
			if(cnt == Cnt){
				ans++;
				cnt = 0;
				Cnt = 0;
				i++;
				break;
			}else{
				i++;
			}
		}
	}
	printf("%d" , ans);
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	scanf("%d%d" , &n , &k);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d" , &a[i]);
		if(a[i] == 0 || a[i] == 1)cnt[a[i]]++;
	}
	if(cnt[1] == n)solve1();
	else{
		if(k == 1)solve2();
		else solve3();
	}
	return 0;
}