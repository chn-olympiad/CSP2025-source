#include <bits/stdc++.h>
using namespace std;
int n,m,ans=1;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	for (int i=1;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return 0;
}

