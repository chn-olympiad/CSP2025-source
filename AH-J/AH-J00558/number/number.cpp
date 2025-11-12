#include<bits/stdc++.h>
using namespace std;
string s, ans;
int n;
char a[1000010];
bool f=true;
bool cmp(char a, char b){
	return a>b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(char c : s)
		if(c>='0'&&c<='9')
			a[++n]=c;
	sort(a+1, a+1+n, cmp);
	if(a[1]=='0')cout << 0;
	else for(int i=1; i<=n; i++)cout << a[i];
	return 0;
}
