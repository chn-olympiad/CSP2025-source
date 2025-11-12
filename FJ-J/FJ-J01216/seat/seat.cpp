#include<bits/stdc++.h>
using namespace std;
int n, m;
bool check(int a, int b){
	return a > b;
}
int main(){
	cin >> n >> m;
	int val = 0;
	vector<int> a(n*m+10);
	for (int i = 0; i < n*m; i++){
		cin >> a[i];
		if (i == 0){
			val = a[i];
		}
	}
	sort(a.begin(),a.end(),check);
	int seat = 0;
	for (int i = 0; i < a.size(); i++){
		if (a[i] == val){
			seat = i+1;
			break;
		}
	}
	int sm = seat/n+1;
	int sn = 0;
	if (seat % n == 0){
		sn = n;
		sm = seat/n;
	}else if (sm % 2 == 0){
		sn = n- seat%n+1;
	}else if (sm % 2 != 0){
		sn = seat%n;
	}
	cout << sm << ' ' << sn;
	return 0;
}
