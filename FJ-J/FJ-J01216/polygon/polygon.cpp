#include<bits/stdc++.h>
using namespace std;
long long sum = 0;
int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> a(n+1);
	for (int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = a[i].first;
		if (i) a[i].second += a[i-1].second;
		int j = i;
		while (j && a[j].first < a[j-1].first){
			swap(a[j],a[j-1]);
			j--;
		}
	}
	for (int i = 3; i <= n; i++){
		cout << i << endl;
		for (int j = i-1; j < n; j++){
			int nowsum = a[j].second - a[j-i].second;
			if (j == i-1){
				nowsum = a[j].second;
			}
			cout << nowsum << ' ';
			if (a[j].first * 2 < nowsum){
				sum++;
			}
		}
		cout << endl;
		sum %= 998244353;
	}
	cout << sum;
	return 0;
}
