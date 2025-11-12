//暴力 O(n3)  =(  (40分？)我特殊性质呢？=(    ==p 
#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
#define inf 998244353
using namespace std;
ll jc(ll n){
	ll sum=1;
	for(int jj=2;jj<=n;jj++){
		sum*=jj;
		sum%=inf;
	}
	return sum;
}
ll poo(ll x){
	return pow(2,x);
} 
ll n,a[10050],b[10050],tx,ans,bzd=100,lans,po2;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    //cout<<jc(5);
    scanf("%lld",&n); 
    for(int i=1;i<=n;i++){
	    scanf("%lld",&a[i]);
	    b[i]=b[i-1]+a[i];
	}
    sort(a+1,a+1+n);
    for(int i=n;i>=3;i--){
    	tx=b[i-1]-a[i]-1;
    	for(int j=1;j<=i-3;j++){
    		cout<<" j="<<j;
    		lans=0,po2=0;
    		for(int k=j;k<=i-3;k++){
    			cout<<" k="<<k;
    			po2++;
    			lans+=a[k];
    			cout<<" lans="<<lans;
    			if(lans>tx){
    				po2--;
    				lans-=a[i];
    				break;
				}
			}
			cout<<" po2="<<po2;
			ans%=inf;
			ans-=poo(po2);
			ans%=inf;
			cout<<" i:"<<i<<" "<<ans<<endl;
		}
		ans+=(poo(i-1))%inf;
	}
	printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
	return 0;
}
//5 1 2 3 4 5
