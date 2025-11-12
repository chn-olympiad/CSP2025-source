#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, city1, city2, fee;
	cin >> n >> m >> k;
	vector<int> vec;
	for (int i = 0; i < m; i++){
		cin >> city1 >> city2 >> fee;
		vec.push_back(fee);
	}
	sort(vec.begin(), vec.end());
	int sum = 0;
	for (int i = 0; i < n - 1; i++)
		sum += vec[i];
	cout << sum;

	return 0;
}

