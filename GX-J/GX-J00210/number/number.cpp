#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout) ;
	string s ;
	cin >> s ;
	//vector <int> a1 ;
	int a1[10] ;
	memset(a1,0,sizeof(a1));
	//long long a2 = 0 ;
	for(long long i = 0 ;i<s.length();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			//string s2 = s.substr(0,1) ;
			//int b1 = stoi(s2) ;
			//a1.push_back(s[i]-48) ;
			a1[s[i]-48] = a1[s[i]-48]+1 ;
			//a2 = a2+1 ;
		}
	}
	//sort(a1,sizeof(a1)) ;
	for(int i = a1[9] ;i>0;i--){
		cout << 9 ;
	}
	for(int i = a1[8] ;i>0;i--){
		cout << 8 ;
	}
	for(int i = a1[7] ;i>0;i--){
		cout << 7 ;
	}
	for(int i = a1[6] ;i>0;i--){
		cout << 6 ;
	}
	for(int i = a1[5] ;i>0;i--){
		cout << 5 ;
	}
	for(int i = a1[4] ;i>0;i--){
		cout << 4 ;
	}
	for(int i = a1[3] ;i>0;i--){
		cout << 3 ;
	}
	for(int i = a1[2] ;i>0;i--){
		cout << 2 ;
	}
	for(int i = a1[1] ;i>0;i--){
		cout << 1 ;
	}
	for(int i = a1[0] ;i>0;i--){
		cout << 0 ;
	}
	return 0 ;
}
