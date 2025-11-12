#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL num[11]={};

bool cmp(char x, char y){
	return x > y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin >> s;
	
	for(auto c:s){
		if(c >= '0' && c <= '9'){
			num[c-'0']++;
		}
	}
	bool flag=false;
	
	for(int i=9;i>=0;i--){
		if(flag==false && i == 0){
			cout << 0;
			exit(0);
		}
		if(num[i]){
			flag=true;
			for(LL j=1;j<=num[i];j++){
				cout << i;
			}
		}
		
	}
	
	cout << endl;
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}

