#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10; 
string s;
int num[N];
int cnt;

signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for(char i : s){
		if('0'<=i&&i<='9'){
			num[cnt++] = i-'0';
		}
	}
	sort(num, num+cnt, greater<int>());
	for(int i=0;i<cnt;i++) cout << num[i];
	
	return 0;
}
