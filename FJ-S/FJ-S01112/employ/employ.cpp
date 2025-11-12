#include<bits/stdc++.h>
using namespace std;
int n,m,c[550];
long long ans=1;
char s[550];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>s[i];
}
for(int i=1;i<=n;i++){
	cin>>c[i];
}
for(int i=1;i<=m;i++){
	ans=(ans*n)%998244353;
	n-=1;
}
cout<<ans;
	return 0;
}