#include<bits/stdc++.h>
using namespace std;
int a[10];
string s;
int main(){
	ifstream r("number.in");
	ofstream w("number.out"); 
	r>>s;
	for (int i=0;i<(int)s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			w<<i;
		}
	}
	
	r.close();
	w.close();
	return 0;
} 
