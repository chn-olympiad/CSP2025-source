#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const int N=505;
int n,m,s[N],a[N],sz[N];
void solve(){
	int tmp_a=0,ta=0;
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='0'){
			s[i]=0;
		}else{
			s[i]=1;
		}
		tmp_a+=s[i];
		sz[i]=sz[i-1];
		if(s[i]==0) sz[i]++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>0) ta++;
	}
	if(tmp_a==n){
		if(ta<m){
			cout<<0<<"\n";
			return;
		}else{
			long long ans=1;
			for(long long i=2;i<=n;i++){
				ans=ans*i%mod;
			}
			cout<<ans<<"\n";
			return;
		}
	}else if(n==m){
		cout<<0<<"\n";
		return;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
