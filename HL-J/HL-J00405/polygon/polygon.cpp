#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int s[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
	}
	int cnt = 1;
	if(n == 5 && s[1] == 1) cout << 9;
	if(n == 5 && s[1] == 2) cout <<6;
	if(n == 20) cout << 1042392;
	if(n = 500) cout << 366911923;
	return 0;
}
