#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[20005],t[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int p=q;
	while(p--){
		cin>>t[q-p];
	}
	return 0;
}
