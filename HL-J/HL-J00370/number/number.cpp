#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int a[maxn],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++k] = s[i] - '0';
		}
	}
	sort(a+1,a+k+1,greater<int>());
	for (int i = 1; i <= k; i++){
		cout << a[i];
	}
	cout << endl;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

