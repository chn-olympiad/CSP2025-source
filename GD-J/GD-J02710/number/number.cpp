#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
char ch;
int n, a[15];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while(cin >> ch){
		if('0' <= ch && ch <= '9')
			a[ch - '0']++;
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= a[i];j++)
			cout << i;
	}
	cout << endl;
	return 0;
}

// 怎么优化 a? 
// 哎我会了！！！ 
