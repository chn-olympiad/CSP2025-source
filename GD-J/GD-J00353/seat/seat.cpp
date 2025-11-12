#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n*m;++i)
		cin >> a[i];
	int sc = a[1];
	sort(a+1, a+1+n*m, greater<int>());
	for(int i=1;i<=n*m;++i){
		if(sc==a[i]){
			cout << (i-1)/n+1;
			if((i-1)/n%2==0){ //ÆæÊýÁÐ 
				if(i%n==0)
					cout << ' ' << n;
				else
					cout << ' ' << i%n;
			} else {
				if(i%n==0)
					cout << ' ' << 1;
				else
					cout << ' ' << n-i%n+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
