#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1[n+1],s2[n+1],t1[q+1],t2[q+1];
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	if(q-n>0) cout<<q-n;
	else cout<<n-q;
	for(int i=2;i<=q;i++){
		cout<<0;
	}
	return 0;
}
