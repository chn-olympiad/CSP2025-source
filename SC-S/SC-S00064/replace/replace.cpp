#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q;
string s[N][3];
string t1, t2;
int num = 0;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i=1;i<=n;++i){
		cin >> s[i][1] >> s[i][2];
		if(count(s[i][1].begin(), s[i][1].end() ,'b') == 1 &&
		 count(s[i][2].begin(), s[i][2].end()  ,'a')) == 1){
		 	num++;
		 }
	}
	for(int i=1;i<=q;++i){
		cin >> t1 >> t2;
		cout << num*2 << endl;
	}
	
	return 0;
}