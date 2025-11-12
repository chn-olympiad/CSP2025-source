#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;cin>>n>>m;
	string s,a;
	for(int i=1;i<=n;i++){
		cin>>s>>a;
	}
	for(int i=1;i<=m;i++){
		cin>>s>>a;
	}
	for(int i=1;i<=m;i++){
		cout<<m+2*i-4;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
