#include<bits/stdc++.h>
using namespace std;
int n,m;
const int mod=998244353;
int P(int n,int m){
	int a=1;
	for(int i=1;i<=n;i++){
		a=(a*i)%mod;
	}
	int b=1;
	for(int i=1;i<=(n-m);i++){
		b=(b*i)%mod;
	}
	return (a/b)%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;int x;
	int ans=0;
	for(int i=1;i<=m;i++){
		cin>>x;
	}
	for(int i=m;i<=n;i++){
		ans+=P(n,i)%mod;
	}
	cout<<ans;
	return 0;
} 
