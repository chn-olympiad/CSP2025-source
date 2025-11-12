#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
long long sxs=1;
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>s[i];
	for (int i=0;i<m;i++){
		cin>>c[i];
		if (c[i]==0) n-=1;
	}if (m>n) cout<<0;
	else for (int i=1;i<=n;i++) sxs=sxs*i%998244353;
	cout<<sxs;
}
