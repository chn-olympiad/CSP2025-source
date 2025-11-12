#include<bits/stdc++.h>
using namespace std;

const long long MOD=998244353;
int c[600];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	cin>>c[i];
    
    if(n==m){
    	for(int i=0;i<=s.size();i++){
    		if(s[i]=='0'){
    			cout<<0;
    			return 0;
			}
		}
		long long ans=1;
		for(int i=n;i>=1;i--){
			ans*=n;
			ans%=MOD;
		}
		cout<<ans;
	}else{
		long long ans=1;
	   for(int i=n;i>=1;i--){
	     ans*=n;
	     ans%=MOD;
	   }
	   cout<<ans;
	}
	return 0;
}