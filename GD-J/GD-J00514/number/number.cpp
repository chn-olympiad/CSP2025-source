#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1="";
	int num=0,a[100001]={},b[100]={};
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(b[i]!=0){
			for(int j=1;j<=b[i];j++){
				cout<<i;
			}
		}
	}
	
	
	return 0;
}
