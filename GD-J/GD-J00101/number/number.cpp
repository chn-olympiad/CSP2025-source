#include<bits/stdc++.h>
using namespace std;
char c;
string s;
int n[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	c=s[1];
	for(int i=0;c!='\0';i++){
		c=s[i];
		if(int(c)>47&&int(c)<59){
			n[int(c)-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(;n[i]>=1;n[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
