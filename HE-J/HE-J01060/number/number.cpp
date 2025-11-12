#include<bits/stdc++.h>
using namespace std;
string s,num;
int qb[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.size();
	for(int i = 0;i<len;i++){
		if(s[i] >='0'&&s[i] <= '9'){
			qb[s[i]-'0']++;
		}		
	}	
	for(int i = 9;i>=0;i--){
		if(qb[i] !=0){
			for(int j = 1;j<=qb[i];j++){
				cout << i;
			}
		}
	}
	return 0; 
} 
