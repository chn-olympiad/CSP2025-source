#include<bits/stdc++.h>
using namespace std;

int t;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t --){
		int s;
		cin >> s;
		int num = 0;
		for(int i = 0; i < s; i ++){
			int u, v, w;
			cin >> u >> v >> w;
			num += max(max(u, v), w);
		}
		cout << num << endl;
	}
}
