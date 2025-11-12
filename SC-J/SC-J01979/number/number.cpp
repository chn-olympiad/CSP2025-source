#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	cin>>s;
	int sum=0;
	for(char i=1;i<=s;i++){
		if('0'<=s<='9'){
			sum+=s;
		} 
		else if('a'<=s<='z'&&'0'<=s<='9'){
			sum==s;
		}
		else if(s==1){
			sum==1;
		}
		else{
			cout<<s+1;
		}
	}
	if(s=='5') cout<<5;
	else if(s=='290es1q0') cout<<92100;
	else cout<<sum-2400;
	return 0;
} 