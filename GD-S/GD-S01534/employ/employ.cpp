#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,sum[505],fir[505],c[505],cnt1,cnt[505];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s="%"+s;
	for(long long i=1;i<=n;i++){
		cnt1+=s[i]=='1';
	}
	for(long long i=1;i<=n;i++)cin>>c[i],cnt[c[i]]++;
	sort(c+1,c+1+n);
	if(cnt1<m){
		cout<<0;
		return 0;
	}
	long long ans=1;
	for(long long i=1;i<=n;i++)ans*=i,ans%=mod;
	if(m==n){
		cout<<ans;
		return 0;
	}
	if(m==1&&cnt1==1){
		cout<<ans;
		return 0;
	}
	ans=0;
	do{
		long long gg=0;
		for(long long i=1;i<=n;i++){
			if(s[i]=='0'||gg>=c[i])gg++;
		}
		if(n-gg>=m)ans++,ans%=mod;
	}while(next_permutation(c+1,c+1+n));
	for(long long i=0;i<=n;i++){
		for(int j=1;j<=cnt[i];j++){
			ans*=j,ans%=mod;
		}
	}
	cout<<ans;
}
/*
101
1 1 2
*/
