#include <bits/stdc++.h>
using namespace std;

char c;
int num[15];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	while(cin >> c)
		if(c >= '0' && c <= '9')
			num[int(c-'0')]++;
	for(int i = 9;i >= 0;i--)
		while(num[i]){
			cout << i;
			num[i]--;
		} 	
	
	return 0;
}
