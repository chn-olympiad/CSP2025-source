#include<bits/stdc++.h>
using namespace std;
int nxt[1000005];
void getnxt(string s){
	int j=0;
	for(int i=0;i<s.size();i++){
		
		 if(i!=j&&s[i]==s[nxt[j]]) j++;
		while(s[i]!=s[j]&&j!=0) j=nxt[j-1];
		
		nxt[i]=j;
		
		
		
	}
}
signed main(){
	string s;
	cin>>s;
	getnxt(s);
	for(int i=0;i<s.size();i++){
		cout<<nxt[i]<<" ";
	}
}
