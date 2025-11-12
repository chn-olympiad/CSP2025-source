#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,maxx=LLONG_MIN;
ll a[500000];
ll s1,s2;
ll xorr(ll x1,ll x2){
	ll p=0;
    ll q=0;
    ll c[1001]={0};
    ll b[1001]={0};
    ll m=0;
	while(x1>0){
		c[p]=x1%2;
		p++;
		x1=x1/2;
	}
	while(x2>0){
		b[q]=x2%2;
		q++;
		x2=x2/2;
	}
	if(q>p){
		for(ll i=p+1;i<=q;i++){
			c[i]=0;
		}
		for(ll i=q;i>=0;i--){
		    for(ll j=q;j>=0;j--){
		        if(c[i]==b[j]){
		        	c[i]=0,b[j]=0;
		        	break;
				}else{
					c[i]=1,b[j]=1;
					break;
				}
        	}
    	}
    	for(ll i=q;i>=0;i--){
    		m+=c[i]*(2^i);
		}
	}else if(q<p){
		for(ll i=q+1;i<=p;i++){
			b[i]=0;
		}
		for(ll i=p;i>=0;i--){
		    for(ll j=p;j>=0;j--){
		        if(c[i]==b[j]){
		        	c[i]=0,b[j]=0;
		        	break;
				}else{
					c[i]=1,b[j]=1;
					break;
				}
        	}
    	}
    	for(ll i=p;i>=0;i--){
    		m+=c[i]*(2^i);
		}
	}else{
		for(ll i=p;i>=0;i--){
		    for(ll j=q;j>=0;j--){
		        if(c[i]==b[j]){
		        	c[i]=0,b[j]=0;
		        	break;
				}else{
					c[i]=1,b[j]=1;
					break;
				}
        	}
    	}
    	for(ll i=p;i>=0;i--){
    		m+=c[i]*(2^i);
		}
	}
	return m;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	ll x1=1,x2=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=i;j++){
			if(j==1){
				s2+=a[j];
			}else if(i==n){
				s1+=a[i];
			}else{
				s1+=xorr(a[i],a[i-1]);
		    	s2+=xorr(a[j],a[j-1]);
			}
		}
		if(s1==s2&&s2==k){
			x1++;
		}
		if(x1>maxx){
			maxx=x1;
		}
		s1=s2=0;
		x1=1;
	}
	cout<<maxx;
	return 0;
}

