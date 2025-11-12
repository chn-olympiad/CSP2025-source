#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mt=998244353;
int n,m;
string s;
int ss=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		int cs;
		scanf("%lld",&cs);
	}
	for(int i=n;i>=1;i--){
		ss*=i;
		ss%=mt;
	}printf("%lld",ss);
	return 0;
}
