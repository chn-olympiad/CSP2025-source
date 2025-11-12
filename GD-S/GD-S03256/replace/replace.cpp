#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
const int N=2e3+5;
int n,q; string s[N][2],t[2],res;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;++i){
		cin>>t[0]>>t[1];
	}
	return 0;
} 
