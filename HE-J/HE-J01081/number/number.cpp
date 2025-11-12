#include<bits/stdc++.h>
using namespace std;
string s;
char c[10000],maxx='0';
int cnt=0,n=0;
int main( ){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int j=0;j<s.size();j++){
		for(char i='0';i<='9';i++){
			if(s[j]==i){
				 c[j]=s[j];
				 n+=1;
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int j=0;j<s.size();j++){
			if(c[j]>maxx){
				maxx=c[j];
				cnt=j;	
			}
		}	
		cout<<maxx;
		maxx='0';
		c[cnt]='0';
	}

	return 0;
}
