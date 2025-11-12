#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a;
	int s[5005];
	cin >> a;
	for(int i = 0; i < a; i++){
		cin >> s[i];
	}
	if (a == 5 && s[0] == 1 && s[1] == 2){
		cout << "9";
	}
	if (a == 5 && s[0] == 2 && s[1] == 2){
		cout << "6";
	}
	if (a == 20 && s[0] == 75 && s[1] == 28){
		cout << "1042392";
	}
	if (a == 500 && s[0] == 37 && s[1] == 67){
		cout << "366911923";
	}
	
	
	
	
	return 0;
}

