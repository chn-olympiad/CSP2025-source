#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
int b[N];
int cnt;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.size();
	for(int i = 0;i < len;i++){
		if (s[i] >= '0' && s[i] <= '9'){
			b[cnt++] = s[i] - '0';
		} 
	}

	sort(b,b+cnt,cmp);
	for(int i = 0;i < cnt;i++){
		cout << b[i];
	}
	return 0;
}


