#include<bits/stdc++.h>
using namespace std; 
int n,q;
string s[200005][2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a==b)cout<<1<<'\n';
		else cout<<0<<'\n';
	}
	return 0;
}

