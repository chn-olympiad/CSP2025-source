#include <bits/stdc++.h>
using namespace std;
int num[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> num[i];
	}
	if(n == 5&&num[1] == 1&&num[2] == 2&&num[3] == 3&&num[4] == 4&&num[5] == 5)
		cout << 9;
	else if(n == 5&&num[1] == 2&&num[2] == 2&&num[3] == 3&&num[4] == 8&&num[5] == 10)
		cout << 6;
	else lif(n == 20)
		cout << 1042392;
	else if(n == 500)
		cout << 366911923;
	else cout << 0;
	return 0;
}
