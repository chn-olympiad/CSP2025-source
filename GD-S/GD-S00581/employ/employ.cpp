#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,s[505],p[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int num=n;
	for(int i=1;i<=n;i++)
	cin>>s[i];
	for(int j=1;j<=n;j++){
		cin>>p[j];
		if(!p[j])num--;
	}
	if(n-num<m)
	cout<<0;
	else{
		long long ans=1;
		for(int i=2;i<=n;i++)
		ans=ans*i%mod;
		cout<<ans;
	}
	return 0;
}
