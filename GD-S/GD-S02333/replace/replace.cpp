#include<bits/stdc++.h>
using namespace std;
const int it=9999999;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	string s[it];
	int t[it];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
