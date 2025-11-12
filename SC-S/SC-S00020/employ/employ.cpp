#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,mod=998244353;
int n,m;
string s;
int a[N];
int ans,cnt,num;
int qpow(int a,int b,int mo){
	int res=1;
	while(b){
		if(b&1) res=a*res%mo;
		a=a*a%mo;
		b>>=1;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	ans=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) cnt++;
	}
	num=1;
	for(int i=1;i<=n-cnt;i++){
		num*=i;
		num%=mod;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
//	cout<<ans<<endl;
	ans=ans*qpow(ans,mod-2,mod)%mod;
	cout<<(ans+mod)%mod;
	return 0;
} 
/*


*/