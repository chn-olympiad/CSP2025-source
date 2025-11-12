#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int a[N];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int k = 0;
	int len = s.size();
	for(int i = 0;i < len;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++k] = s[i] - '0';
		}
	} 
	sort(a + 1, a + 1 + k, cmp);
	for(int i = 1;i <= k;i++){
		cout << a[i];
	}
	
	return 0;
}