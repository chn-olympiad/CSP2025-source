#include<bits/stdc++.h>
using namespace std;
int n, m, a[105];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= (n * m);i++){
		cin >> a[i];
	} 
	int g;
	int k = a[1];
	sort(a + 1, a + (n * m) + 1, cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == k){
			g = i;
			break;
		}
	}
	if(g % n == 0){
		cout << g / n << ' ';
		if((g / n) % 2 == 0){
			cout << 1 << endl;
		}else{
			cout << n << endl;
		}		
	}
	else{
		cout << g / n + 1 << ' ';
		if((g / n) % 2 == 0){
			cout << g % n << endl;
		}else{
			cout << n - (g % n) + 1 << endl;
		}
	}
	return 0;
}
