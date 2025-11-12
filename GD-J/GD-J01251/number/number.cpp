#include<bits/stdc++.h>
using namespace std;
char s;
int t[200];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
	if(s<='9'&&s>='0')t[s]++;
	}
	for(int i='9';i>='0';i--){
		for(int j=1;j<=t[i];j++)
		cout<<char(i);
	}
	return 0;
} 
