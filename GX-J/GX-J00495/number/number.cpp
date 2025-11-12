#include<bits/stdc++.h>
using namespace std;
string n;
int ans, sum;
int m[10000001];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
	cin >> n;
	ans = n.size();
	for(int i = 0; i < ans; i++){
		if(n[i] >= '0' && n[i] <= '9'){
			sum++;
			m[sum] = n[i] - '0';
		}
	}
	sort(m + 1, m + sum + 1);
	for(int i = sum; i >= 1; i--)
		cout << m[i];
	return 0;
}
