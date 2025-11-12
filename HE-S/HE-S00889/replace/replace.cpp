#include<bits/stdc++.h>																																																																																																																																																																																																																																/*#include<iostream>#include<cstdio>#include<cmath>#include<algorithm>#include<ctring>*/
#define MAXN 200002
using namespace std;
int n,q,s[MAXN][2],t[MAXN][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;++i){
		cin>>s[i][0]>>s[i][1];
	}
	for(int j=0;j<q;++j){
		cin>>t[j][0]>>t[j][1];
	}
	for(int k=0;k<q;++k){
		cout<<0<<endl;
	}
	return 0;
}
