#include<bits/stdc++.h>
using namespace std;
int n,m,h=0;
int a[600];
char s[600];
bool d=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for (int i=1;i<=m;i++){
		cin>>a[i];
		if (a[i]==0)d=false,h++;
	}
	int ans=1;
	for (int i=1;i<=n-h;i++){
		ans=ans*i%998244353;
	}
	if (n==m&&d==false)cout<<0;
	else cout<<ans;
}
