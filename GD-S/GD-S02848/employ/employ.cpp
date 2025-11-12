#include<iostream>
#define mod 998244353
#define int long long
using namespace std;
int n,m,s[100001],c[100001],f=1,p;
int fac(int x){
	int ans=1;
	for(int i=1;i<=x;i++)
	ans=((ans%mod)*(i%mod))%mod;
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		s[i]=ch-'0';
		if(s[i]==0) f=0;
	}
	for(int i=1;i<=n;i++)
	  cin>>c[i],p+=(c[i]>0); 
	if(f==1)
		cout<<fac(p)<<"\n";
	else if(m==1)
	    cout<<fac(p)<<"\n";
	else if(m==n){
		if(f==1) cout<<fac(p)<<"\n";
		else cout<<0<<"\n";
	}    
}
