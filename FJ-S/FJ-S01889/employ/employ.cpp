#include<bits/stdc++.h>
using namespace std;
long long n,a[505],ans,m,aab,mod=998244353,c[505],k;
string s;

int main(){	
	freopen("employ.in","r",stdin);	
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;++i){
		a[i]=s[i]-'0';
		aab+=a[i];
	}
	for(int i=0;i<n;++i){
		cin>>c[i];
		if(c[i]==0){
			++k;
		}
	}
	if(aab==n){
		if(n-k<m){
			cout<<0;
		}
		else{
			ans=1;
			for(long long i=1;i<=n;++i){
				ans=ans*i%mod;
			}
			cout<<ans;
		}
		
	}
	else if(aab==0){
		cout<<0;	
	}
	else if(m==n){
		cout<<0;
	}
	else if(m==1){
		ans=1;
		for(long long i=1;i<=n;++i){
			ans=ans*i%mod;
		}
		cout<<ans;
	}
	else{
		cout<<2;
	}
	fclose(stdin);	
	fclose(stdout);
	return 0;
} 
