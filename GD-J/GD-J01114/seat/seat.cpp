#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++){
		cin >> a[i];
	}
	int x = a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1; i <= n * m; i ++){
		if (a[i] == x){
			if (((i + n - 1) / n ) % 2 == 0)cout <<(i + n - 1) / n << " "<< n + 1 - i % n;
			else {
				if (i % n == 0){
					if ((i / n) % 2 == 1){
						cout <<(i + n - 1) / n << " "<< n;
					}else{
						cout <<(i + n - 1) / n << " "<< 1;
					}
				}
				else cout <<(i + n - 1) / n << " "<< i % n;
			}
			return 0;
		}
	}
	return 0;
}
