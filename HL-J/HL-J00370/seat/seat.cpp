#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int R_CSP_J = a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for (int i = 1; i <= n * m; i++){
		if(a[i] == R_CSP_J){
			if(i % n){
				int lie,hang;
				lie = i / n + 1;
				if(lie % 2){
					hang = i % n ;
				}else{
					hang = n - (i % n - 1);
				}
				cout << lie << " " << hang << endl;
			}else{
				int lie,hang;
				lie = i / n;
				if(lie % 2){
					hang = n;
				}else{
					hang = 1;
				}
				cout << lie << " " << hang << endl;
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
