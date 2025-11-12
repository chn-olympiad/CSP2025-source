#include<iostream>
using namespace std;
#define ll long long
const int MAXN=505;
const int mod=998244353;
int n,m;
char s[MAXN];
int c[MAXN];
int sp_A=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s[i];
		if (s[i]=='1') sp_A++;
	}
	for (int i=1;i<=n;i++) cin>>c[i];
	if (n==m){
		bool flag=true;
		for (int i=1;i<=n;i++){
			if (s[i]=='0'){
				cout<<0;
				flag=false;
			}
		}
		if (flag){
			ll ans=1;
			for (int i=1;i<=n;i++){
				ans=ans*i%mod;
			}
			cout<<ans;
		}
	}
	else if (sp_A==n){
		int cnt=0;
		for (int i=1;i<=n;i++){
			if (c[i]!=0) cnt++;
		}
		ll ans=1;
		for (int i=1;i<=cnt;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
	}
	return 0;
}
// rp++;

