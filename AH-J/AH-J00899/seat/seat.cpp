#include<bits/stdc++.h>
using namespace std;

int n, m, x;
int a, b = 1;

int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n>> m;
	int num = n * m;
	cin >> a;
	for (int i = 1; i < num; i++){
		cin >> x;
		if (a < x) b++;
	}
	//cout << "c "<< b<< endl;
	int j = (b - 1) / n + 1;
	if (j % 2 == 1){
		cout << j<< " "<< b - (j - 1) * n<< endl;
	}
	else{
		cout << j<< " "<< j * n - b + 1<< endl;
	}
	
	//cout << "c "<< b<< endl;
	//int i = 1, j = 1;
	//bool zf = 1;
	//for (int z = 1; z <= b; z++, i++){
	//	if (i > n){
	//		i = 1;
	//		j++;
	//	}
	//}
	//if (i > n) i -= n;
	//cout << "c "<< j<< " "<< i<< endl;
	//if (j % 2 == 1){
	//	cout << j<< " "<< i - 1<< endl;
	//}
	//else{
	//	cout << j<< " "<< n - i + 1<< endl;
	//}
//	cout << b<< endl;
//	int i = 0;
//	for (; i < m; i++){
//		if (n * i > b) break;
//		if (n * i == b){
//			cout << i<< " "<< n;
//			return 0;
//		}
//	}
//	b -= --i * m;
//	if (i % 2 == 0) cout << i + 1<< " "<< b;
//	else cout << i + 1<< " "<< n - b + 1;
	
	return 0;
}
