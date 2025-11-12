#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e6,M=998244353;
ll a[N],n;
bool bo[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	string s;
	cin>>s;
	ll ans=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bo[i]=false;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
