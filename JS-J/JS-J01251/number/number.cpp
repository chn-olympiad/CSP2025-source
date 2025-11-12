#include<bits/stdc++.h>
using namespace std;
unsigned int num[10]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(unsigned int i=0;i<s.size();i++){
		if((s[i]>='0')&&(s[i]<='9')){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(unsigned int j=0;j<num[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
