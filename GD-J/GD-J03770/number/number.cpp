#include <bits/stdc++.h>
using namespace std;
string s;
int a[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin >> s;
	int cnt =1;
	for (int i =0;i<s.length();i++){
		if('0' <= s[i]&&s[i] <= '9'){
			a[cnt++] = s[i]-'0';
		}
	}
	sort(a+1,a+cnt,cmp);
	cnt--; 
	for (int i =1;i <= cnt;i++){
		cout << a[i];
	}
	return 0;
} 
