#include<bits/stdc++.h>
using namespace std;
string s;
int l,n,a[1000006];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	l = s.length();
	for (int i = 0;i < l;i++){
		if ('0' <= s[i] && s[i] <= '9'){
			a[++n] = s[i]-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for (int i = 1;i <= n;i++) cout << a[i];
	return 0;
}
