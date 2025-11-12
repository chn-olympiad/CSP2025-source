#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=550;
const ll mod=998244353;
int n,m;
string s;
int c[N];
ll dp[N][N];
ll qz[N];
int qd[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		qz[c[i]]++;
	}
	for(int i=1;i<=n;i++) qz[i]=(qz[i]+qz[i-1])%mod;
	sort(c+1,c+n+1);
	bool flag=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		qd[i]=qd[i-1];
		if(s[i]!='1'){
			flag=0;
			cnt++;
			qd[i]++;
		}
	}
	ll ans=1;
	for(ll i=1;i<=n;i++) ans=ans*i%mod;
	if(flag){
		cout<<ans;
		return 0;
	}
//	cout<<cnt<<endl;
	if(cnt>n-m){
		cout<<0;
		return 0;
	}
	int tot=0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') continue;
		for(int j=qd[i]+1;j<=n;j++){
			int c=0;
			for(int k=i-1;k>=0;k--){
				if(s[k]=='0'){
					c++;
					continue;
				}
				dp[i][j]=(dp[i][j]+dp[k][j-c-1]*(qz[j-1]-(j-c-1-qd[k]))%mod+mod)%mod;
			}
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	ll ss=0;
	int idx=n;
	while(c[idx]=='0') idx--;
//	cout<<"HA\n";
//	cout<<idx<<endl;
	for(int i=n-m+1;i<=n;i++){
		ll tmp=1;
//		cout<<i-qd[idx]<<endl;
		for(ll j=n-(i-qd[idx]);j>n-(i-qd[idx])-cnt;j--) tmp=tmp*j%mod;
//		cout<<tmp<<endl;
		ss=(ss+dp[idx][i]*tmp%mod)%mod;
	}
	cout<<(ans-ss+mod)%mod;
	return 0;
}
