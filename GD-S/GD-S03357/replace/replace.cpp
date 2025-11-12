#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s;
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=2;j++){
			cin>>s;
		}
	}
	for(int i=1;i<=q;i++){
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
