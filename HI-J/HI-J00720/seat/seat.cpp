#include<bits/stdc++.h>
using namespace std;
int b[105];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n = 0, m = 0, num = 0;
	cin >> n >> m;
	int cnt = n*m;
	for(int i = 1; i <= cnt; i++){
		cin >> b[i];
	}
	int k = b[1];
	sort(b+1,b+cnt+1,cmp);
	for(int i = 1; i <= cnt; i++){
		if(b[i] == k){
			num = i;
			break;
		} 
	}
	if(num <= n){
		cout << "1" << " " << num;
		return 0;
	}
	if(num > n){
		int l = 0, h = 0;
		if(num%n == 0){
			l = num/n ;
			if( l % 2 == 0){
				cout << l << " " << 1;
				return 0;
			}
			else{
				cout << l  << " "<< n;
				return 0;
			}
		}
		else{
			l = num/n+1 ;
			if(l % 2 == 0){
				h = n-num%n+1;
				cout << l << " " << h;
				return 0;
			}
			if(l % 2 == 1){
				h = num % n;
				cout << l << " " << h;
				return 0;
			}
		}
	}
	return 0;
}
