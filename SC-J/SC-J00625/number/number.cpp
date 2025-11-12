#include <iostream>
using namespace std;
string s;
int a[10];
int main(){
	cin >> s;
	int s1 = s.size();
	for(int i = 0 ; i <= s1 ; i++)if(s[i] >= '0' && s[i] <= '9')a[int(s[i])-48]++;	
	for(int i = 9 ; i >= 0; i--){
		for(int j = 1 ; j <= a[i] ; j++) cout << i;  
	}	
	return 0;
} 