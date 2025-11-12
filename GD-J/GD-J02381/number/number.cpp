#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char a[N];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt = 1;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[cnt] = s[i];
			cnt++;
		}
	}
	sort(a, a + cnt, cmp);
	for(int i = 0 ; i < cnt ; i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

