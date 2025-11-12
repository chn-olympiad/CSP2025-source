#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
typedef long long ll;
ll n,m,ans=1,pe[505],yz[505],cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int t; cin>>t;
		pe[t]++;
	}
	for(int i=n-1;i>=0;i--) pe[i]=pe[i+1]+pe[i];
	int cnt=0;
	for(int i=0;i<s.length();i++){
		yz[i+1]=cnt;
		if(s[i]=='0') cnt++;
	}
	

	for(int i=n;i>=1;i--){
		if(pe[yz[i]+1]>0){
			ans=(ans*pe[yz[i]+1])%mod;
			cnt++;
		}
		for(int j=yz[i]+1;j>=1;j--) pe[j]--;
	}
	
	cout<<ans;
	return 0;
}
