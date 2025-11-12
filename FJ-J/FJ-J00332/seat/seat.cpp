#include <iostream>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105] = {},n,m,z,ans = 0;
	cin >> n >> m;
	int x = n * m;
	for (int i = 1; i <= x; i++){
		cin >> a[i];
	}
	int q = a[1];
	for (int i = 1; i <= x; i++){
		for (int j = 1; j <= x - i + 1; j++){
			if(a[j] < a[j + 1]){
				z = a[j];
				a[j] = a[j + 1];
				a[j + 1] = z;
			}
		}
	}
	for (int i = 1; i <= x; i++){
		if(a[i] == q){
			ans = i;
			break;
		}
	}
	cout << ans / n + 1 << " ";
	if ((ans / n + 1) % 2 == 0){
		cout << m - (ans - 1) % m;
	}
	else{
		cout << (ans - 1) % m + 1;
	}
	return 0;
}
