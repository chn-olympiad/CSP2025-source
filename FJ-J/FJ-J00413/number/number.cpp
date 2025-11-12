#include<bits/stdc++.h>
using namespace std;
int t[10]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
	int len=0,num=0;
	cin>>s;
	while(s[len]){
		if(s[len]<='9'&&s[len]>='0'){
			num++;
			t[s[len]-'0']++;
		}
		len++;
	}
	for(int i=9;i>=0;i--){
		if(t[i]!=0){
			for(;t[i]!=0;t[i]--) cout<<i;
		}
	}
}
