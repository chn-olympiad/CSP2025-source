#include <bits/stdc++.h>
using namespace std;
long long read(){
	long long a=0;
	char c=getchar();
	while(c<'0' or c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	} 
	return a;
}
long long s[20],dp[20][20][333333],n,m,mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.in","w",stdout) ;
	n=read();m=read();
	if(m==n){
		long long ans=0;
		for(int i=1;i<=n;i++){
			char c;
			cin>>c;
			ans+=c-'0';
		}
		if(n==ans){
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod; 
			}
			cout<<ans;
		}else{
			cout<<"0";
		}
	}else{
			long long ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod; 
			}
			cout<<ans;
		
	}
	return 0;
} 
