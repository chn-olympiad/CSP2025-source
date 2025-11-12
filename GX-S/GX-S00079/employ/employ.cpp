#include<bits/stdc++.h>
using namespace std;
int n,m,f[510];
string s;
int ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	
	while(n){
		ans=(ans*n)%998244353;
		n--;
	}
	cout<<ans%998244353;
	return 0;
}
