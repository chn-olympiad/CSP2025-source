#include<bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;
char a[N];

int main(){
	
	freopen("number.in" ,"r" ,stdin);
	freopen("number.out" ,"w" ,stdout);
	
	string s;
	cin >> s;
	memset(a , '-' ,sizeof a);
	
	sort(s.begin() , s.end());

	for(int i=0 ;i<=s.size() ;i++){
		
		if(s[i] >= '0' && s[i] <= '9'){
			a[i] = s[i] ;
		}
		
	}
	
	
	for(int i=s.size() ;i>=0 ;i--){
		if (a[i] != '-') cout << a[i] ;
	}

	
	return 0;
} 
// ×îÖÕ 
