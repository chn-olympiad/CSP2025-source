#include<bits/stdc++.h>
using namespace std;
string s;
int m,n,k[501],f[501],ans,g[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	f[1]=(int)s[0]-48;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+(int)s[i-1]-48;
	}
	for(int i=1;i<=n;i++){
	}
	cout<<ans;
	return 0;
} 
