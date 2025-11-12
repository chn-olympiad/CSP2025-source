#include<bits/stdc++.h>
using namespace std;
long long a[20];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	long long len = s.size();
	for(int i = 0;i <= len;i++){
		char c = s[i];
		if(c >= '0'&&c <= '9') a[c-'0']++;
	}for(int i = 9;i >= 0;i--)
		if(a[i])
			for(int j = 1;j <= a[i];j++)
				cout << i;
	cout << endl;
	return 0;
}
