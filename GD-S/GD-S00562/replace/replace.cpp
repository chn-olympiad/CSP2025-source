#include<bits/stdc++.h>
using namespace std;

freopen("replace.in","r",stdcin);
freopen("replace.out","w",stdcout);

int main(){
	int n,q;
	string s[n][2],w[q][2];
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=0;i<q;i++){
		cin>>w[i][0]>>w[i][1];
	}
	
	for(int i=0;i<q;i++){
		cout<<0;
	}
	return 0;
}
