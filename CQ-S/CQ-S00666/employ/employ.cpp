#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
int a[505],b[505];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	if(m==n){
		int ans=1;
		for(int i=1;i<=n;i++)ans*=i,ans%=mod;
		cout<<ans;
		return 0;
	}
	string s;
	cin>>s;
	s=" "+s;
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=s[i]-'0';
	if(cnt<m)cout<<0,exit(0);
	if(cnt==n){
		int ans=1;
		for(int i=1;i<=n;i++)ans*=i,ans%=mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=i;
	do{
		int cnt=0,res=0;
		for(int i=1;i<=n;i++){
			if(i>n-m+res)break;
			if(cnt>=a[b[i]]||s[i]=='0')cnt++;
			else res++;
			if(res>=m){
				ans++;
				break;
			}
		}
		ans%=mod;
	}while(next_permutation(b+1,b+n+1));
	cout<<ans;
	return 0;
}