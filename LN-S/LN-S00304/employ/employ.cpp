#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353ll;
int a[520];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tot=0,tot1=0;
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='1') tot++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0) tot1++;
	}
	sort(a+1,a+n+1);
	if(n<=10){
		string h="";
		for(int i=1;i<=n;i++){
			h+=(char)(64+i);
		}
		int ans=0;
		do{
			int be_ob=0;
			for(int i=0;i<n;i++){
				if(a[int(h[i])-64]<=be_ob or s[i]=='0'){
					be_ob++;
					continue;
				}
			}
			if(n-be_ob>=m) ans++;
		}while(next_permutation(h.begin(),h.end()));
		cout<<ans;
		return 0;
	}
	if(tot==n){
		if(m>tot1) cout<<0,exit(0);
		long long ans=1;
		for(long long i=1;i<=n;i++){
			//cout<<ans<<'\n';
			ans*=i;
			ans%=mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}