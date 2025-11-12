#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;
string s;
int a[N];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int cnt = 0;
	s = " " + s;
	for(int i = 1;i <= s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cnt++;
			a[cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + cnt + 1, cmp); 
	int ans = 0;
	for(int i = 1;i <= cnt;i++){
		ans = ans * 10 + a[i];
	}
	cout << ans << endl;
	
	
	
	
	return 0;
}