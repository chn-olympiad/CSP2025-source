#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=0,b=0,c=0,e[100010]={};
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9')e[s[i]-'0']++;
	}
    for(int i=9;i>=0;i--){
    	for(int j=0;j<e[i];j++)cout<<i;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

