#include <bits/stdc++.h>
using namespace std;

namespace solve{
	void main(){
		string s;
		cin >> s;
		vector<int> Count(10, 0);
		for (char ch : s){
			if ('0' <= ch && ch <= '9')
				Count[ch-'0']++;
		}
		int ind = 9;
		while(ind>=0){
			if (Count[ind]){
				cout << ind;
				Count[ind]--;
			} else{
				ind--;
			}
		}
	}
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve::main();
	return 0;
}
