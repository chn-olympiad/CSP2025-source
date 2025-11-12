#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a[1000000];
	int j = 0, l = s.length();
	for(int i = 0; i < l; i++){
		if(isdigit(s[i])){
			a[j] = (s[i]-'0');
			j++;
		}
	}
	sort(a, a+j, cmp);
	for(int i = 0; i < j; i++){
		cout << a[i];
	}
}
