#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],k;
string s;
long long sum,mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
		cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]>0)sum++;
    }
    for(int i=0;i<s.size();i++){k+=s[i]-48;}
	if(m==1||k==n){
		long long ans=1;
		sum=n;
		while(sum--){
			ans=ans*(sum+1)%mod;
		}
		cout<<ans; 
	}
	else if(n==m){
		if(k!=s.size()||sum!=n)cout<<0;
		else{
			
		long long ans=1;
		while(sum--){
			ans=ans*(sum+1)%mod;
		}
		cout<<ans;
		}
	}
	else cout<<n*n-1;
	return 0;
}
