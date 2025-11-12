#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll n,m,cnt,ans=1,a[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cnt--;
		}
	}
	for(int i=1;i<=cnt;i++){
		ans*=cnt;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}