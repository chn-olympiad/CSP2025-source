#include<bits/stdc++.h>
using namespace std;

string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 1000; j++)
		if(s[j] >= '0' && s[j] <= '9'){
			if(s[j] <= s[j+1]){
				int t = s[j];
				s[j] = s[j+1];
				s[j+1] = t;
			}           
		}
	}
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cout<<s[i];     
		}
	}
	return 0;
} 
