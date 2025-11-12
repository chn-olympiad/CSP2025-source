#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int ton[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
		cin >>s;
		
	int len=s.length();
	for (int i=0;i<len;i++){
		if (s[i]>='0'&&s[i]<='9'){
			ton[s[i]-'0']++;
		}
	}

	
	for (int i=9;i>=0;i--){
		for (int j=1;j<=ton[i];j++){
			
			cout <<i;
		}
	}
	
	

	return 0;
} 
