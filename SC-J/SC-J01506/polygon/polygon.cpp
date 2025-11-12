#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int n;
int a[N];
int sum;
int maxnum;
void dfs(int x, int num, int maxx, int summ) {
	if (num == maxnum) {
		//cout << "total:" << maxnum << " x:" << x << " num:" << num << " maxx:" << maxx << " summ:" << summ << "\n";
		if (summ > 2 * maxx) {
			//cout << "YESSSSSSSSSSSSSSSSSSSSSSSSSS\n";
			sum++;
			return;
		}
		return;
	}
	for (int i = x + 1; i <= n; i++) {
		int t = maxx;
		if (a[i] > maxx) {
			maxx = a[i];
		}
		//cout << "i:" << i << " num:" << num << " maxx:" << maxx << " summ:" << summ << "\n";
		dfs(i, ++num, maxx, summ + a[i]);
		num--, maxx = t;
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		maxnum = i;
		//cout << "数量：" << i << "\n";
		for (int j = 1; j <= n - i + 1; j++) {
			dfs(j, 1, a[j], a[j]);
		}
	}
	cout << sum;
	return 0;
}
/*
	    |			|			-----------------             |
		|			|                          /			  |
		|			|						  /				  |
		|			|						 /				  |
		|			|						/				  |
		|			|					   /			      |
		|-----------|					  /					  |
					|					 /					  |
					|					/					  |
					|				   /					  |
					|				  /						  |
					|				 /						  |
		------------|				/----------------		  |------------------


		|			|            |-------------------------|  |------------------
		|			|            |            |            |  |
		|			|            |            |            |  |
		|			|            |            |            |  |
		|			|            |            |            |  |
		|			|            |            |            |  |
		|-----------|            |            |            |  |
					|            |            |            |  |
					|            |            |            |  |
					|            |            |            |  |
					|            |            |            |  |
					|            |            |            |  |
		------------|            |            |            |  |------------------

		-------------            /						|-------------
			  |					 /						|			/
			  |					 /						|          /
			  |					 /						|		  /
			  |					 /-------------			|--------/
			  |					 /			  |			|  \
			  |					 /			  |			|    \
			  |					 /			  |			|      \
			  |					 /			  |			|        \


*/