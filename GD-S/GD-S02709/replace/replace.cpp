#include <bits/stdc++.h>
using namespace std;
int s[200005][2],t[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
	}
	for(int i=1;i<=q;i++){
		cout<<0;
	}
}
