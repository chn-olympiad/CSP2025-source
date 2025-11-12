#include<iostream>
#include<cstdio>
using namespace std;
#define int long long 
const int mod = 998244353;
char s[510];
int pre[510];
int c[510];
int cnt = 0;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>s[i];
	for(int i = 1;i<=n;i++)pre[i] = pre[i-1]+s[i];
	int fac = 1;
	for(int i = 1;i<=n;i++)fac = fac*i%mod;
	cout<<fac;
}
