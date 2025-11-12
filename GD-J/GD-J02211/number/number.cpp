#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	 
	int shu[10] = {0};
	string s;
	cin >> s;
	
	int len = s.size();
	
	for(int i = 0; i < len; i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			shu[s[i] - '0'] ++;
		}
	}
	
	for(int i = 9; i >= 0; i --){
		for(int j = 0; j < shu[i]; j ++){
			cout << i;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
