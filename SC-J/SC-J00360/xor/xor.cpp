#include<bits/stdc++.h>
using namespace std;
#define ll int
ll in(){
	ll k=0;
	bool f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+(c^48);
		c=getchar();
	}
	return f?k:-k;
}
void out(ll x){
	ll pos=0;
	char buf[20];
	if(x<0){
		x=-x;
		putchar('-');
	}
	buf[pos++]=x%10^48;
	x/=10;
	while(x){
		buf[pos++]=x%10^48;
		x/=10;
	}
	while(pos){
		putchar(buf[--pos]);
	}
}
void outel(ll x){
	out(x);
	putchar('\n');
}
ll n,k,a[5000010],sum[5000010],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=in();k=in();
	for(ll i=1;i<=n;i++){
		a[i]=in();
		sum[i]=sum[i-1]^a[i];
	}
	ll xh=min(n/5+1,1000);
	for(ll x=1;x<=xh;x++){
		ll now=0;
		for(ll i=x;i<=n;i++){
			for(ll j=i;j<=n;j++){
				if(!(sum[j]^sum[i-1]^k)){
					now++;
					i=j;
					break;
				}
			}
		}
		ans=max(ans,now);
	}
	out(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}