#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll P=998244353;
ll n,m,a[505],cnt,ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]) cnt++;
	}
	ans=1;
	for(ll i=2;i<=cnt;i++){
		ans*=i;
		ans%=P;
	}
	cout<<ans;
	return 0;
}
