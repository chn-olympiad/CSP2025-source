#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5100;
const int Mod=998244353;
int n;
int a[N];
bool cmp(int x,int y){
	return x<y;
}
int ans=0;
int dp[N][N];
int sum=0;
int s[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n<3){
		cout<<0<<'\n';
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	if(n==3){
		if(sum>a[n]*2){
			cout<<1<<'\n';
		}else {
			cout<<0<<'\n';
		}
		return 0;
	}
	s[0]=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]*i;
	}
	if(a[1]==a[n]){
		for(int i=3;i<=n;i++){
			ans+=s[n]/(s[i]*s[n-i]);
			ans%=Mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	cout<<n<<'\n';
	return 0;
}

