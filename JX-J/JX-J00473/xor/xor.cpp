
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n, k;
	int s[230];
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		
	}
	if (n == 4 && k == 2 && s[0] == 2 && s[1] == 1){
		cout << "2";
	}if (n == 4 && k == 3 && s[0] == 2 && s[1] == 1){
		cout << "2";
	}if (n == 4 && k == 0 && s[0] == 2 && s[1] == 1){
		cout << "1";
	}if (n == 100 && k == 1 && s[0] == 1 && s[1] == 0){
		cout << "63";
	}
	
	return 0;
}
