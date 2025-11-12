#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

string s, n;
char a;
char ans[N];
bool cmp(char x, char y){
	return y < x;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	int l = n.size();
	n = ' ' + n;
	int j = 1;
	for(int i = 1; i <= l; i++){
		if(n[i] >= '0' && n[i] <= '9'){
			ans[j] = n[i];
			j++;
		}
	}
	sort(ans + 1, ans + l + 1, cmp);
	for(int i = 1; i <= l; i++){
		s += ans[i];
	}
	cout << s;
	return 0;
} 	
