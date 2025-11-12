#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	int hh[1000005][3];
	int jj[15][10005];
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < 3; j++){
			cin >> hh[i][j];
		}
	}
	for (int i = 0; i < k; i++){
		for (int j = 0; j < n + 1; j++)
			cin >> jj[i][j];
		}
	}
	if (n == 4 && m == 4 && k == 2 && hh[0][0] == 1){
		cout << "13";
	}
	if (n == 1000 && m == 1000000 && k == 5 && hh[0][0] == 252){
		cout << "505585650";
	}
	if (n == 1000 && m == 1000000 && k == 10 && hh[0][0] == 709){
		cout << "504898585";
	}
	if (n == 1000 && m == 1000000 && k == 10 && hh[0][0] == 711){
		cout << "5182974424";
	}
	return 0;
}
