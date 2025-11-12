#include<bits/stdc++.h>
using namespace std;
int read(){
	int ret=0,op=1;char in=getchar();
	while(!isdigit(in)){if(in=='-'){op=-1;}in=getchar();}
	while(isdigit(in)){ret=(ret<<3)+(ret<<1)+(in^48);in=getchar();}
	return ret*op;
}
int mp[20];
string str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i+=1){
		if(isdigit(str[i]))mp[str[i]-'0']+=1;
	}
	for(int i=9;i>=0;i-=1){
		for(int j=1;j<=mp[i];j+=1){
			printf("%d",i);
		}
	}
	return 0;
}