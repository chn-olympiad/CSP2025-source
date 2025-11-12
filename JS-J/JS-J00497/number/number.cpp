#include <bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	freopen(stdin, 'r', "number.in");
	freopen(stdout, 'w', "number.out");
	cin >> s;
	int n = s.size();
	for (int i = 1;i <= n;i++){
		if (isdigit(s[i])){
			a[s[i] - '0']++;
		}
	}
	for (int i = 9;i >= 0;i --){
		for (int j = 1;j <= a[i];j ++){
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
