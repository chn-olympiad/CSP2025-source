#include <bits/stdc++.h>
using namespace std;
int main(){
	freeopen("seat.in" ,"r",stdin)
	freeopen("seat.out" ,"w",stdout)
	int a,b,sum,c[10000],num,k;
	cin >> a >> b;
	sum = a * b;
	for(int i = 0;i <= sum;i++){
		cin >> c[i];
		
	}
	num = c[0];
	sort(c + 1,c + sum + 1);
	for(int i = 0;i<=sum;i++){
		if(c[i] == num){
			k = i;
		}
	}
	for(int i = 0;i<=a;i++){
		for(int j = 0;j <= b;j++){
			if(k == j){
				cout << i << j;
			}
		}
	}
	return 0;
}
