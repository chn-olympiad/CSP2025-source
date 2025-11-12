#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a;
int ans[1000005], cnt;
int main(){
	freopen("number4.in", "r", stdin);
	freopen("number4.out", "w", stdout);
	cin >> a;
	for(int i = 0; i < a.size(); i++){
		int t = a[i];
		if(isdigit(t)){
			ans[++cnt] = t - '0';
		}
	}
	sort(ans +  1, ans + cnt + 1, greater<int>());
	for(int i = 1; i <= cnt; i++){
		cout << ans[i]; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
