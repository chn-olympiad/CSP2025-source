#include<bits/stdc++.h>
using namespace std;

string _list;
vector<long long> num_list;

bool cmp (long long prev, long long next) {
	return prev > next;
}

int main () {
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> _list;
	for (int i = 0; i < _list.size(); i++) {
		if (_list[i] >= '0'&&_list[i] <= '9') {
			num_list.push_back(_list[i] - '0');
		}
	}
	sort(num_list.begin(), num_list.end(), cmp);
	if (num_list[0] == 0) {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < num_list.size(); i++) 
		cout << num_list[i];
	cout << "\n";
	return 0;
}
