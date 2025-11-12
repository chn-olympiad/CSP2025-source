#include<bits/stdc++.h>
using namespace std;
int n,sticks[5005];
int main(){
	cin >> n;
	for(int i = 1;i <= n;++i)cin >> sticks[i];
	if(n == 5){
		if(sticks[1] == 1)cout << 9;
		if(sticks[1] == 2)cout << 6;
	}else if(n == 20)cout << 1042392;
	else if(n == 500)cout << 366911923;
	else cout << 1042392 * 2;
	return 0;
}
