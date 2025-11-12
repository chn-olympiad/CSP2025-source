#include <bits/stdc++.h>
using namespace std;
string s;
int n,a[1000005];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n = s.length();
	int c = 0;
	for (int i = 0;i < n;i++){
		if (s[i] <= '9'){
			a[c++] = s[i] - '0';
		}
	}
	sort(a,a + n,cmp);
	bool f = false;
	for (int i = 0;i < c;i++){
		if (a[i] != 0) f = true;
	}
	if (!f){
		cout << 0;
		return 0;
	}
	for (int i = 0;i < c;i++) cout << a[i];
	return 0;
}
