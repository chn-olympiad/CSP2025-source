#include <iostream>
using namespace std;
int n,m;
int a[105];
int hump[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++){
		cin >> a[i];
		hump[a[i]]++;
	}
	int cnt = 0;
	for (int i = 100;i >= 0;i--){
		if (hump[i] > 0){
			cnt++;
		}if (i == a[1]){
			break;
		}
	}
	int lie;
	if (cnt%n == 0){
		lie = cnt/n; 
	}else{
		lie = cnt/n+1;
	}
	cout << lie << " ";
	int ncnt = cnt-(lie-1)*n;
	if (lie%2 == 0){
		cout << n-ncnt+1;
	}else{
		cout << ncnt;
	}return 0;
}
