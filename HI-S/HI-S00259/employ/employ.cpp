#include<bits/stdc++.h>
using namespace std;
long long ans;
char s[505];
int c[505];
int main(){
freopen("employ3.in","r",stdin);
freopen("employ.out","w",stdout);
long long n,m;
ans=1;
cin>>n>>m;
for(int i=n;i<=n;i++){
	cin>>s;
	for(int j=1;j<=n;j++) cin>>c[i];
}
if(n<=100){
	ans=1;
	for(int i=n;i>=1;i--) ans=ans*i;
	cout<<ans%998244353;
}
if(n<=500){
	if(n<=100){
	ans=1;
	for(int i=n;i>=1;i--) ans=ans*i;
	cout<<ans;//%998%244%353;
}
}
    else{
     if(m==1)	
    	ans=1;
	for(int i=n;i>=1;i--) ans=ans*i;
	cout<<ans%998244353;
	if(m<=n){
	ans=1;
	for(int i=n;i>=1;i--) ans=ans*i;
	cout<<ans%998244353;	
		
		
	}	
	}
	







return 0;
}

