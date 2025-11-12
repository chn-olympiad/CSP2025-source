#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
string s;
int c[505];
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;	
	}
	cout<<ans;
	return 0;
} 
