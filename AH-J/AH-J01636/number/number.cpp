#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t[100]={};
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(t[i]!=0){
			for(int j=0;j<t[i];j++)cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
