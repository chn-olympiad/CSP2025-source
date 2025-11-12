#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a[1000005] = {};
	int tt = 0;
	int t = s.length();
	for (int i = 0;i < t;i++){
		if (s[i] >= '0' && s[i] <= '9'){
			tt++;
			a[tt] = s[i] - '0';
		}
	}
	sort(a + 1,a + 1 + tt);
	for (int i = tt;i >= 1;i--){
		printf("%d",a[i]);
	}
	return 0;
} 
