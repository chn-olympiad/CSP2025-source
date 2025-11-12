#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=9;i>=0;i--){
		for(int j=0;j<len;j++){
			if(s[j]-'0'==i){
			cout<<s[j];
		}
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
