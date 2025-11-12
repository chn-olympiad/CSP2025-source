#include<bits/stdc++.h>
using namespace std;
string s;
long long num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int ls=s.length();
	for(int i=0;i<ls;i++){
		int si=s[i];
		if(si>=48 && si<=58) num[si-48]++;
	} 
	for(int i=9;i>=0;i--){
		int numi=num[i];
		for(int j=1;j<=numi;j++){
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
} 
