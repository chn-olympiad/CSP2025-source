#include<bits/stdc++.h>
using namespace std;
int n,m;
const int mod= 998244353;
long long power(long long a,long long b){
	long long res=0;
	while(b){
		if(b&1) res=(res+a)%mod;
		a=(a+a)%mod;
		b=b>>1;
	}
	
	return res%mod;
}
int a[1000000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int flag=1; 
	int ts=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) ts--; 
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'&&m==n){
			cout<<0<<endl;
			return 0;
		}else if(s[i]=='0'){
			flag=0;
		}
	}
	long long ans=1;
	if(flag==1){
		for(long long i=1;i<=ts;i++){
			ans=power(ans,i);
			cout<<ans<<" ";
		}
		cout<<ans;	
	}else{
		cout<<0;
	}
	
	
	return 0;
} 
