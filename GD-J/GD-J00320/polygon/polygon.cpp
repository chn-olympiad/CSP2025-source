#include <bits/stdc++.h>
using namespace std;
int n , a[5100] , c , p[5100] , sum;
void fun(int s , int i , int d){
	if(i <= n){
		if(d < s){
			p[d] = a[i];
			fun(s , i + 1 , d + 1);
			for(int j = i + 1;j <= n;j++) fun(s , j , d);
		}else{
			sum = 0;
			p[d] = a[i];
			sort(p + 1 , p + d + 1);
			for(int j = 1;j <= d;j++) sum += p[j];
			if(sum > p[d] * 2) c++;
			fun(s , i + 1 , d);
		}
	}
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 3;i <= n;i++) fun(i , 1 , 1);
	cout << c - 1;
	return 0;
} 
