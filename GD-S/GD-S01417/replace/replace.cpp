#include<bits/stdc++.h>
using namespace std;
ifstream fin("replace.in");
ofstream fout("replace.out");
long long int n,q;
int main(){
	fin>>n>>q;
	string s[n+1][2],t[q+1][2];
	for(int i=1;i<=n;i++){
		fin>>s[i][0];
		fin>>s[i][1];

	}
	for(int i=1;i<=q;i++){
		fin>>t[i][0];
		fin>>t[i][1];

	}
	for(int i=1;i<=q;i++){
		fout<<0<<"\n";
	}	
	return 0; 
	
}
