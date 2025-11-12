#include<bits/stdc++.h>
using namespace std;

int num[10];
char s;
int k;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (cin >> s){
		k = (int)s;
		if (k >= 48 && k <= 57) num[k - 48]++;
	}
	for (int i = 9; i >= 0; i--) if (num[i] != 0) for(int j = 1; j <= num[i]; j++) cout << i;
	cout << "\n";
	return 0;
} 




/*
1 -> 49
2 -> 50
..
9 -> 57
*/
