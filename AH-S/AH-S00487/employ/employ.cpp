#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,v[510];
unsigned long long f[510];
string s;
bool fA=true,fB=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	f[0]=1;
	for(LL i=1;i<=500;i++) f[i]=(f[i-1]*i)%998244353,cout<<f[i]<<"\n";
	cin>>s;
	fA=s.find('0')==string::npos;
	if(fA) cout<<f[n];
	else cout<<0;
	return 0;
}
