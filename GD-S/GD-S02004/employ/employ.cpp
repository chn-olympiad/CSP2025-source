#include<bits/stdc++.h>
using namespace std;
const int mx=508;
const int mod=998244353;
#define ll long long
void solve(){
	int a[mx];
	ll n;
	string s;
	int m;
	ll ans=1;
	cin>>n>>m;
	cin>>s;
	int c0,c1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)c0++;
		else c1++;
	}
	for(int i=0;i<n;i++){
		if(s[i]='0')c0++;
		else c1++;
	}
//	for(int i=1;i<=c0;i++){
//		ans=(ans*i)%mod;
//	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t=1;
	//scanf("%d",&t);
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

