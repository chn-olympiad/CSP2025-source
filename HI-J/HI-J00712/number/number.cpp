#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	string s;
	getline(cin,s);
	string res="";
	int n;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])){
			res+=s[i]; 
			
		}

	}

	for(int i=0;i<res.size();i++){
		
		if(res[i]>=res[i+1]){
			cout<<res[i-1]<<res[i]<<res[i+1]; 
		}
	
	}
	return 0;
}
//2 9 0 1 0
//9 2 1 0 0
