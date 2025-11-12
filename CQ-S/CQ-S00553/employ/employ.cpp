#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=998244353;
ll n,m,ans;
ll s[505];
ll c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) ans=(ans*i)%M;
	cout<<ans<<"\n";
	return 0;
}
