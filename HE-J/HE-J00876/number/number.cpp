#include<bits/stdc++.h>
using namespace std;
const int M = 1e6+5;

int num[15];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	for(int i=0; i<=10; i++)  num[i] = 0;
	
	for(int i=0; i<s.size(); i++){
		if(s[i] == '0')   num[0]++; 
		if(s[i] == '1')   num[1]++; 
		if(s[i] == '2')   num[2]++; 
		if(s[i] == '3')   num[3]++; 
		if(s[i] == '4')   num[4]++; 
		if(s[i] == '5')   num[5]++; 
		if(s[i] == '6')   num[6]++; 
		if(s[i] == '7')   num[7]++; 
		if(s[i] == '8')   num[8]++; 
		if(s[i] == '9')   num[9]++; 
		continue;
	}
	
//	for(int i=0; i<=10; i++){
//		cout << num[i] << " ";
//	}
//	cout << endl;
	
	long long ans = 0;

	for(int i=9; i>=0; i--){
		if(num[i] == 0)	continue;
		for(int j=1; j<=num[i]; j++){
			ans = ans*10+i;	
		}	
//		cout << endl;
//		cout << i << " " << ans << " ";
	}
	
	cout << ans;
	
	
	return 0;
}
