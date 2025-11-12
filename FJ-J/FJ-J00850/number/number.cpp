#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
string s;
long long e=0;
char a[N];
bool cmp(char a, char b){
	return a>=b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			e++;
			a[e]=s[i];
		}
	}
	sort(a+1,a+1+e,cmp);
	for(int i=1; i<=e; i++){
		cout << a[i];
	}
	return 0;
}
