#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
int c[100010];
int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long ans=1;
	for(long long i=1;i<=n;i++){
		ans=ans*i;
		ans=ans%mod;
	}
	cout<<ans<<endl;
	return 0;
}
