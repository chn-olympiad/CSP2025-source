#include<bits/stdc++.h>
using namespace std;
int n,a[500005],ans,ma=-1;
const long long mod=998244353;
long long fp(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1){
			res=res*a%mod;
		}
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++) ma=max(ma,a[i]);
    if(n<=20){
        for(int i=0;i<(1<<n);i++){
    	    int sum=0,m=-1,b=0;
    	    for(int j=0;j<n;j++){
    		    if((1<<j)&i){
    			    sum+=a[j+1];
    			    m=max(m,a[j+1]);
    			    b++;
			    }
		    }
		    if(b<3) continue;
		    if(sum>2*m) ans++;
	    }    	
	    cout<<ans;
	}else if(ma==1){
		long long t=fp(2,1LL*n)%mod;
		t=t-1-n-1LL*n*(1LL*n-1)/2;
		cout<<t;
	}
	return 0;
}
