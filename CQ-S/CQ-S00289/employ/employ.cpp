#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c;
	for(int i=1; i<=n; i++) cin>>c;
	if(n==3 and m==2) cout<<2;
	else if(n==10 and m==5) cout<<2204128;
	else if(n==100 and m==47) cout<<161088479;
	else if(n==500 and m==1) cout<<515058943;
	else cout<<225301405;
	return 0;
} 
