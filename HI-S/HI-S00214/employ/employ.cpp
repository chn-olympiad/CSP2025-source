#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll MOD=998244353;
int n,m,c[505];
string s;
ll p;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	p=1;
	for(int i=2;i<=n;i++){
		p=p*i%MOD;
	}
	printf("%lld\n",p);
	return 0;
}
