#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
const int N = 2e5+5;
const int mod = 998244353;
long long n,ans,m,k,d;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;ans=1;k=n;
	for(int i=1;i<=n;i++){
		cin>>d;
		if(d==0)k--;
	}
	if(k<m){
		puts("0\n");
		return 0;
	}
	for(int i=1;i<=k;i++)ans=ans*i%mod;
	cout<<ans;
	return 0;
}
