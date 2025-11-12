#include<bits/stdc++.h>
using namespace std;
int nm[10];
int main(){
	freopen("number.in","r",stdin);  
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	for(int i = 0;i < s.size();i++){
		if(s[i] <= '9' && s[i] >= '0'){
			nm[s[i]-'0']++;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= nm[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
