#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,mod=998244353;
int n,m;
string s;
int c[N]; 
int a[N];
int sum[N];
void solve(){
	int ans=0;
	do{
//		for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//		cout<<' ';
		int cnt=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				sum++;
				continue;
			}
			else{
				if(sum<c[a[i]])cnt++;
				else{
					sum++;
				}
			}
		}
//		cout<<cnt<<'\n';
		if(cnt>=m)ans++,ans%=mod;
	}while(next_permutation(a+1,a+1+n));
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	s=' '+s;
	for(int i=1;i<=n;i++)a[i]=i;
	int f=0;
	int tot=0;
	for(int i=1;i<n;i++){
		if(s[i]=='1')tot++;
		if(!(s[i]==s[i+1] && s[i+1]=='1'))f=1;
	} 
	sum[n]=sum[n-1];
	if(sum[n]=='0')sum[n]++;
	if(s[n]=='1')tot++;
	if(tot<m){
		cout<<0<<'\n';
		return 0;
	}
	if(f==0){ 
		int ans=1;
		for(int i=2;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans<<'\n';
	}
	else{
		solve();
	}
	return 0;
}

