#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5*1e5+10;
long long n, k;
vector <bool> b[MAXN];
vector <bool> sum[MAXN];//存储异或和 
vector <bool> kb;
vector <bool> bijiao;
int xorn(int x, int i){
	while (x >= 1){
		b[i].push_back( (x%2==1)? 1:0);
		x/=2;
		//cout << x << " ";
	}
	while (b[i].size() <= 19){
		b[i].push_back(0);
	} 
	if (i == 1){
		for (int j = 0; j <= 19; j++){
			sum[i].push_back(b[i][j]);
		}
		return 0;
	} else {
		for (int j = 0; j <= 19; j++){
			sum[i].push_back((sum[i-1][j] != b[i][j])?1:0);
		}
	}
	for (int i = 1; i <= n; i++){
		
	}
	//if (b[i].empty == 1) b[i].push_back(0);
	//for (int j = 0; j < b[i].size())
}
int xork(int x){
	while (x >= 1){
		kb.push_back( (x%2==1)? 1:0);
		x/=2;
		//cout << x << " ";
	}
	while (kb.size() <= 19){
		kb.push_back(0);
	} 
	//if (b[i].empty == 1) b[i].push_back(0);
	//for (int j = 0; j < b[i].size())
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	//sort(a, a+n, 1);
	//xorn(1, 2);
	xork(k);
	for (int i = 1; i <= n; i++){
		long long x;
		xorn(x, i);
	}
	/*
	for (int i = 1; i <= n; i++){
		printf("b i:%d ", i);
		for (int j = 0; j < b[i].size(); j++){
			cout << b[i][j];
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++){
		printf("sum i:%d ", i);
		for (int j = 0; j < sum[i].size(); j++){
			cout << sum[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < kb.size(); i++){
		cout << kb[i];
	}
	*/
	int l = 1;//左侧区间 
	bool is_thefirst = 1;
	int cnt = 0;
	//cout << endl << endl;
	for (int i = 1; i <= n; i++){
		for (int m = l; m <= i; m++){
			if (l == i || is_thefirst){
				for (int j = 0; j <= 19; j++){
					bijiao.push_back(sum[i][j]);
				}
			} else {
				for (int j = 0; j <= 19; j++){
					bijiao[j] = ((sum[m][j] != sum[i][j])?1:0);
				}
			}
			is_thefirst = false;
			/*
			printf("i:%d l:%d ", i, l);
			for (int j = 0; j <= 19; j++){
				cout << bijiao[i][j];
			}
			cout << endl;
			*/
			bool if_true = true;
			for (int j = 0; j <= 19; j++){
				if (bijiao[j] != kb[j]){
					if_true = false;
					break;
				}
			}
			if (if_true){
				cnt++;
				l = i;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
} 
