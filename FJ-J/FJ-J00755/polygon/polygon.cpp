#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll Mod=998244353;
int n,a[5010],b[5010],maxx;
ll ans2=0;
void cnt(int x,int k,int kk,ll summ){
	if(k>n)return;
	if(n-k<x-kk)return;
	if(kk>x){
		if(summ>2*b[kk])ans2++;
		return;
	}
	b[kk]=a[k];
	cnt(x,k+1,kk+1,summ+b[kk]);
	cnt(x,k+1,kk,summ);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx=max(a[i],maxx);
	}
	sort(a+1,a+n+1);
    if(n<=3){
    	if(a[1]+a[2]>a[3]){
    		cout<<1;
    		return 0;
    	}
    } 
    if(maxx==1){
    	ll sum=0,val=1;
    	for(int i=3;i<=n;i++){
    		val=1;
    		int k=i;
    	    for(int j=n;j>=n-i+1;j--){
    	    	val*=j;
    	    	while(val%k==0&&k){val/=k,k--;}
    	    	if(!k)val%=Mod;
    	    }
    	    for(int j=1;j<=k;j++){
    	    	val/=j;
    	    }
    	    sum+=val;
    	    sum%=Mod;
    	}
    	cout<<sum;
    	return 0;
    }
    ll ans=0;
    for(int i=3;i<=n;i++){
    	cnt(i,1,1,(long long)0);
    	ans+=ans2;
    	ans2=0;
    	ans%=Mod;
    }
    cout<<ans;
	return 0;
}
