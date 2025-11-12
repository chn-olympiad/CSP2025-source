#include<bits/stdc++.h>
using namespace std;
int t,c,n,m,ans=1;
int a[505],b[505];
int main(){
	string s;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		a[i]=s[i]-'0';
		if(a[i]) t++;
	}
	for(int i=1;i<=n;i++) {
		cin>>b[i];
		if(b[i]) c++;
	}
	if(t<m) cout<<0;	
} 
