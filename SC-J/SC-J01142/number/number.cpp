#include<cstdio> 
#include<iostream>
#include<cstring>
using namespace std;

string s;
int tot[16];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')tot[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tot[i];j++)printf("%d",i);
	}
	return 0;
}