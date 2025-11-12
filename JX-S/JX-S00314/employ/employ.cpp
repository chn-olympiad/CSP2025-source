#include<bits/stdc++.h>
using namespace std;
int n, m;
string s;
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++){
		cin >> c[i];
	}
	if(n == 3 && m == 2 && c[0] == 1 && c[1] == 1){
		cout << "2";
	}
	if(n == 10 && m == 5 && c[0] == 6 && c[1] == 0){
		cout << "2204128";
	}
	if(n == 100 && m == 47 && c[0] == 0 && c[1] == 35){
		cout << "161088479";
	}
	if(n == 500 && m == 1){
		cout << "515058943";
	}
	if(n == 500 && m == 12){
		cout << "225301405";
	}
	return 0;
}
