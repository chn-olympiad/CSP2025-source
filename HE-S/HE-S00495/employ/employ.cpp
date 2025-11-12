#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],ans=1;
char c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) ans=(ans*i)%998244353;
	cout<<ans;
	return 0;
} 
