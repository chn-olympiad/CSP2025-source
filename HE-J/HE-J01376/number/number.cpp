#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
int a[N], cnt = 0;
int to(char ch){
	if(ch - '0' >= 0 && ch - '0' <= 9){
		cnt++;
		return ch - '0';
	}
	else return 0;
}
bool cmp(int x, int y){
	return x > y; 
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		a[i] = to(s[i]);
	}
	sort(a, a + s.size(), cmp);
	for(int i = 0;i < cnt;i++)
		cout << a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
