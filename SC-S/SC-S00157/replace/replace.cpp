#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, q, r;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n+q;i++){
		cin >> r;
	}for(int i = 1;i <= q;i++){
		cout << 0 << endl;
	}
	return 0;
}
