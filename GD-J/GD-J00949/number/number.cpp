#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	string s,ss="";
	fin>>s;
	int ans=0;
	for(int i=0;i<s.length();i++) if('0'<=s[i]&&s[i]<='9') ss=ss+s[i];

	int a[ss.length()]={};
	for(int j=0;j<ss.length();j++){
		int k=0;
	    for(int i=0;i<ss.length();i++) if(ss[i]-'0'>k&&a[i]==0){
	    	k=ss[i]-'0';
		}
	    ans=ans*10+k;
	    for(int i=0;i<ss.length();i++) if(ss[i]-'0'==k&&a[i]==0){
		a[i]=1;i=ss.length(); //no
	}
	}
	fout<<ans;
	
	
	
	
	
	
	fin.close();
	fout.close();
}
