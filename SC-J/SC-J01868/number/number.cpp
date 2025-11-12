#include<bits/stdc++.h>
using namespace std;
int t[10]={};
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=t[i];j>0;j--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 