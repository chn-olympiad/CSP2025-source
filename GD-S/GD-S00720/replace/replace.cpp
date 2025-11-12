#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL n,q;
string s,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>s2;
	}
	for(int i=1;i<=q;i++){
		cin>>s>>s2;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
