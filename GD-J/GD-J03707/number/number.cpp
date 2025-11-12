#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector <int> num(10, 0);
	for(int i = 0; i < s.size(); i++)
		if(s[i] >= '0' && s[i] <= '9') num[int(s[i] - '0')]++;
		bool flag = true;
	for(int i = 9; i >= 0; ){
		if(num[i] > 0){
			if(flag && i == 0){
				printf("0");
				return 0;
			}
			printf("%d", i);
			num[i]--;
			flag = false;
		}
		else i--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
