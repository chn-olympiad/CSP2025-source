#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005], t;
bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for(int i = 0; i < l; i++){
		if(s[i] >= '0' && s[i] <= '9')	a[++t] = s[i] - '0';
	}
	sort(a + 1, a + 1 + t, cmp);
	if(a[1] != 0){
		for(int i = 1; i <= t; i++)	cout << a[i];
	}
	else
	{
		cout << 0;
	}
	puts("");
}
