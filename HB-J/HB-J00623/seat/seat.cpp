#include <bits/stdc++.h>
using namespace std;
int book[109];
int t;
bool cmp(int x , int y){
	return x > y;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> book[i];
	}
	t = book[1];
	sort(book + 1 , book + 1 + n * m , cmp);
	int pos;
	for(int i = 1;i <= n * m;i++){
		if(book[i] == t){
			pos = i;
			break;
		}
	}
//	cout << pos;
	if(pos % n == 0){
		if(pos / n % 2 == 0){
			cout << pos / n << " " << 1;
		}else{
			cout << pos / n << " " << n;
		}
	}else{
		if((pos / n + 1) % 2 == 0){
			cout << pos / n + 1 << " " << n - (pos % n) + 1;
		}else{
			cout << pos / n + 1 << " " << pos % n;
		}		
	}
	return 0;
}
