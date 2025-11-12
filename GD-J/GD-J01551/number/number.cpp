#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ss="";
	cin>>s;
	int len=s.size(),lenss=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0' and s[i]<='9'){
			ss+=s[i];
			lenss++;
		}
	}
	int a[10]={};
	for(int i=0;i<lenss;i++){
		a[ss[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

