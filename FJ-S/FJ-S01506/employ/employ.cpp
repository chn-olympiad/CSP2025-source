#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int a[505],p[505];
void solve(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s=" "+s;
	int sum=0;
	for(int i=1;i<s.size();i++)
	sum+=(s[i]-'0');
//	cout<<sum<<"!\n";
	if(sum<m){
		cout<<0;
		return;
	}
	for(int i=1;i<=n;i++)
	cin>>a[i],p[i]=i;
	if(m==n){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cout<<0;
				return;
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		cout<<ans;
		return;
	}
	int ret=0;
	do{
		int sum=0,ans=0;
		for(int i=1;i<=n;i++)
		if(a[p[i]]>sum&&s[i]=='1')ans++;
		else sum++;
//		cout<<sum;
		ret+=ans>=m;
	}while(next_permutation(p+1,p+1+n));
	cout<<ret;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}
// 1 2 15
// 12pts
