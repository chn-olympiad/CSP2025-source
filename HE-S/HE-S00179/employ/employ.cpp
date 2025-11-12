#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	int a[n+1];
	cin>>n>>m;
	cin>>s;
	bool pda=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'){
			pda=false;
		}
	}
	long long ans=1;
	if(pda){
		for(int i=1;i<=n;i++){
			ans=ans*i;
			ans%=MOD;
		}
		cout<<ans<<endl;
		return 0;
	}
}
