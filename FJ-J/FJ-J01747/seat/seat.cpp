#include <iostream>
#include <algorithm>
using namespace std;
int a[110],n,m;
bool cmp(int a,int b){
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int yuan = a[1];
	for(int i = 1; i < n*m; i++){
		for(int j = i + 1; j <= n*m; j++){
			if(a[i] <= a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}

	int idx = 0;
	for(int i = 1; i <= n*m; i++){
		if(a[i] == yuan){
			idx = i;
			break;
		}
	}
	if(idx % n == 0){
		if((idx / n) % 2 == 0){
			cout << idx / n << " " << 1 << endl;
		}
		else{
			cout << idx / n << " " << n << endl;
		}
	}
	else{
		cout << idx / n + 1 << " ";
		if(idx % (2*n) < n){
			cout << idx % (2*n) << endl;
		}
		else{
			cout << 2 * n + 1 - idx << endl;
		}
	}
	return 0;
}
