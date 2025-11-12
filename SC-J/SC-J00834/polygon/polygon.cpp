#include<bits/stdc++.h>
using namespace std;
const long long int M=998244353;
long long int n,gz[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int t1=1;
	for(int i=1;i<=n;i++){
		cin>>gz[i];
		if(gz[i]!=1)t1=0;
	}
	if(t1){
		long long ans=0;
		int TYU=0;
		for(long long int i=3;i<=n/2;i++){
			long long s=1,I=1;
			for(long long int j=n;j>=n-i+1;j--){
				s*=j;
				s%=M;
				I*=n-j+1;
				I%=M;
			}
			if(n%2==0&&i==n/2){
				if(s%2)TYU=1;
				s/=2;
			}
			ans+=s/I;
			ans%=M;
		}
		ans*=2;
		ans+=TYU+n+1;
		ans%=M;
		ans+=n*(n-1)/2;
		ans%=M;
		cout<<ans;
	}
	return 0;
}