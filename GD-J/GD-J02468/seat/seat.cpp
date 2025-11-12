#include<bits/stdc++.h>
using namespace std;
int a[110],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++){
		cin >> a[i];
		if(i == 1) cnt = a[i];
	}
	sort(a + 1 , a + n * m + 1);
	for(int i = 1 , j = n * m ; j >= 1 ; i++,j--){
		if(a[j] == cnt){
			if(i % n == 0){
				if((i / n) % 2 == 0){
					cout << i / n << " " << 1;
				}else{
					cout << i / n << " " << n;
				}
			}else {
				int q = i / n + 1;
				if(q % 2 == 0){
					cout << q << " " << n + 1 - (i % n);
				}else {
					cout << q << " " << (i % n);
				}
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
