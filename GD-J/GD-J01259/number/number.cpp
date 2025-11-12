#include<bits/stdc++.h>
using namespace std;
int b[30];
int main(){
	freopen("E:GD-J01259/number/number.in","r",stdin);
	freopen("E:GD-J01259/number/number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]!=0){
			b[i]--;
			cout<<i;
		}
	}
	return 0;
} 
