#include <iostream>
using namespace std;
string s="xabcx";
int nxt[105];
int main(){
	for(int i=1,j=0;i<s.size();i++,j++){
		while(s[i]!=s[j]&&j!=0){
			j=nxt[j-1];
		}
		if(s[i]==s[j]){
			nxt[i]=j+1;
		}
	}
	for(int i=0;i<s.size();i++){
		cout<<nxt[i]<<" ";
	}
	return 0;
}
