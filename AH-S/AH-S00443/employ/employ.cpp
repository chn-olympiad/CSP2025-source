#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,sum=1,c[510];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		sum*=i;
		sum%=mod;
	}
	cout<<sum;
	return 0;
}
