#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,f=1;cin>>n>>m;
	string s;cin>>s;
	vector<int> c(n),a(n);
	for(int i=0;i<n;i++) a[i]=i;
	for(auto &i:c) cin>>i;
	for(auto i:s) if(i=='0') f=0;
	if(f){
		ll ans=1;
		for(int i=1;i<=n;i++) (ans*=i)%=mod;
		cout<<ans;
	}else{
		ll ans=0;
		do{
			int cnt=0,sum=0;
			for(int i=0;i<n;i++){
				if(s[i]=='0'||cnt>=c[a[i]]) cnt++;
				else sum++; 
			}
			if(sum>=m) ans++;
		}while(next_permutation(a.begin(),a.end()));
		cout<<ans;
	}
	return 0;
}
