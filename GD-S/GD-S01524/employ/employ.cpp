#include<bits/stdc++.h>
using namespace std;
long long ans,mod=998244353;
bool pan;
int n,m,c[1000005];
char s[1000005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>s[i];
	pan=1;
	for (int i=1;i<=n;i++){
		if (s[i]!='1') pan=0;
	}
	for (int i=1;i<=n;i++) cin>>c[i];
	if (!pan){
		cout<<0;
		return 0;
	}
	ans=1;
	for (int i=n;i>=1;i--){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
