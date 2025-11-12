#include<iostream>
using namespace std;
int main(){
	int n,q;
	string s[1001][3],t[1001][3];
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	for(int i=1;i<=q;i++){
		for(int j=0;j<=t[i][1].length();j++){
			for(int k=t[i][1].length()+1;k>=1;k--){
				
			}
		}
	}
	return 0;
}
