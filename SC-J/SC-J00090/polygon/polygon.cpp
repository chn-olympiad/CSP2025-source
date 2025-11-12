#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],s[5001];
long long Mod=998244353;
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(a[n]==1){
    	long long jc=1,pq=1;;
    	for(int i=n;i>=3;i--){
    		ans=((ans+jc/pq)%Mod);
    		jc=(jc*i)%Mod;
    		pq=(pq*(n-i+1))%Mod;
		}
		cout<<ans;
    	return 0;
	}
	long long m=1<<n;
	for(int i=1;i<=m;i++){
		long long s=1,h=i,l=0,mx=0;
		while(h>0){
			if(h&1){
				l+=a[s];
				mx=max(mx,a[s]);
			}
			h>>=1;
			s++;
		}
		if(l>2*mx){
			ans=(ans+1)%Mod;
		}
	}
	cout<<ans;
	return 0;
}