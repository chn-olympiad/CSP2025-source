#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long c[5005];
long long sum01=0;
long long sum02=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	long long x=s.size();
	for(int i=0;i<x;i++){
		if(s[i]=='0')sum02++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			sum01++;
		}
	}
	if(n==m){
		if(sum01==0&&sum02==0){
			long long ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*i;
				ans=ans%998244353;
			}
			cout<<ans%998244353;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(sum01==0){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i;
			ans=ans%998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	else{
		long long ans=1;
		for(int i=1;i<=n-sum01;i++){
			ans=ans*i;
			ans=ans%998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	return 0;
}
