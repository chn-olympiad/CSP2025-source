#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[105];
string s2[105];
string t1[105];
string t2[105];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		int ans;
		cout<<ans<<'\n';
	}
	return 0;
} 
