#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s[505],c[505];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
} 
