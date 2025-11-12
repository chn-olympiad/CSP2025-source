#include<bits/stdc++.h>
using namespace std;
int n , k , a[500005]  , ps[500005] , qj[500005][3] , l1 , ans;
int yh(int a , int b){
	int ai[35] , bi[35];
	memset(ai , 0 , sizeof(ai));
	memset(bi , 0 , sizeof(bi));
	int la = 0;
	while(a){
		ai[++la] = a % 2;
		a /= 2;
	}
	int lb = 0;
	while(b){
		bi[++lb] = b % 2;
		b /= 2;
	}
	int l = max(la , lb) , an[35];
	memset(an , 0 , sizeof(an));
	for(int i = 1 ; i <= l ; i++){
		if(ai[i] != bi[i]) an[i] = 1;
	}
	int ans = 0;
	for(int i = 1 ; i <= l ; i++){
		ans += pow(2 , i) * an[i];
	}
	return ans;
}
void f(int x , int c){
	ans = max(ans , c);
	for(int i = x + 1 ; i <= l1 ; i++){
		if(qj[x][2] < qj[i][1]){
			f(i , c + 1);
		}
	}
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	for(int i = 1 ; i <= n ; i++){
		ps[i] = yh(ps[i - 1] , a[i]);
	}	
	for(int i = 1 ; i <= n ; i++){
		for(int j = i ; j <= n; j++){
			if(yh(ps[i - 1] , ps[j]) == k){
				qj[++l1][1] = i;
				qj[l1][2] = j;
			}
		}
	}
	for(int i = 1 ; i <= l1 ; i++){
		f(i , 0);
	}
	cout << ans;
	return 0;
}
