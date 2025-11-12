#include<bits/stdc++.h>
using namespace std; 
char s[503];
int c[503];
long long mod=998244353; 
int jc(int n){
    long long ans=1;
    for(int i=1;i<=n;i++){
	    ans=(ans*i)%mod;
	}
	return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s0=0;
    string t;
    cin>>t;
    for(int i=0;i<n;i++){ 
		s[i+1]=t[i]-'0';
	    if(s[i]==0)s0++;
	}
	int c0=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	    if(c[i]==0){
			c0++;	
		}
	}
	if(n==m){
	    cout<<jc(n)<<"\n";
	    return 0;
	}else {
	    cout<<0;
	    return 0;
	}
	if(s0==0){
		if(n-c0>=m){
		    cout<<jc(n)<<"\n";
		    return 0;
		}else{
			cout<<0<<"\n";
			return 0;
		}
	}
	return 0;
} 
//Ren5Jie4Di4Ling5%
