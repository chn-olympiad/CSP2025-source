#include<bits/stdc++.h>
using namespace std;
char c;
int d[12];
bool flag;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(scanf("%c",&c)!=EOF){
		if(c>='0'&&c<='9'){
			d[c-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i!=0) flag|=d[i];
		for(int j=1;j<=d[i];j++){
			s=s+char(i+48);
		}
	}
	if(flag){
		for(int i=0;i<s.size();i++){
			printf("%c",s[i]);
		}
	}
	else cout<<0;
	return 0; 
} 
