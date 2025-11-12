#include <bits/stdc++.h>
using namespace std;
int awa[1230000];
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	//////////////////////////////////////////////////////////////////////
	string s;
	cin >> s;
	int n = s.size();
	int cnt = 0;
	for(int i = 0; i <= n - 1; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cnt++;
			awa[cnt] = s[i] - '0';
		}
	}
	sort(awa+1, awa+cnt+1, cmp);//From BiggerNum to SmallerNum
	for(int i = 1; i <= cnt; i++) cout << awa[i];
	//////////////////////////////////////////////////////////////////////
	fclose(stdin);
	fclose(stdout);
	return 0;
}













