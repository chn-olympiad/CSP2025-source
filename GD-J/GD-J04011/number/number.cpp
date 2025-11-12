#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	
	long long num[10] = {0,0,0,0,0,0,0,0,0,0};
	
	for(int i = 0; i < s.size();i++){
		int temp = s[i] - '0';
		if(temp <= 9 && temp >= 0){
			num[temp]++;
		}
	}
	
	for(int i = 9; i >= 0; i--){
		
		for(int j = 0; j < num[i]; j++){
			cout<<i;
		}
		
	}
	return 0;
}
