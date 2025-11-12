#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[5000005][3];
string t[5000005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	cout<<n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
