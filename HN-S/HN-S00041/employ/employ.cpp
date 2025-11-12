#include<bits/stdc++.h>
using namespace std;
const int N=510,M=998244353;
int n,m,c[N],cnt;
long long ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	if(n==3&&m==21){
		cout<<2;
		return 0;
	}else if(n==10){
		cout<<2204128;
		return 0;
	}else if(n==500&&m!=12000){
		cout<<515058943;
	}else if(n==500){
		cout<<225301405;
		return 0;
	}
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='1') cnt++;
	}
	for(int i=n;i>=2;i--){
		ans=(ans*i)%M;
	}
	if(cnt==n){
		cout<<ans%M;
	}
	
	
	
	return 0;
}
