#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(isdigit(s[i])){
			cnt++;
			a[cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + 1 + cnt);
	if(a[cnt] == 0){
		printf("%d", 0);
		return 0;
	}
	for(int i = cnt; i >= 1; i--){
		printf("%d", a[i]);
	}
	return 0;
}
