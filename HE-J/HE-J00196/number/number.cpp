#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long a[N];
int j;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(isdigit(s[i])){
			a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a, a+j, cmp);
	for(int i = 0; i < j; i++){
		cout << a[i];
	}
	return 0;
} 
