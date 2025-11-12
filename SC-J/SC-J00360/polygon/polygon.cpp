#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
ll n,a[5010],f[25000010],sum[5010],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=in();
	for(ll i=1;i<=n;i++){
		a[i]=in();
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	f[sum[1]]=1;
	f[sum[2]]=f[sum[1]];
	for(ll i=3;i<=n;i++){
		for(ll j=sum[i-1];j>=1;j--){
			f[sum[i]]+=f[j];
		}
	}
	for(ll i=n;i>=1;i--){
		for(ll j=sum[n];j>=2*a[i]+1;j--){
			ans=(ans+f[j])%998244353;
		}
	}
	out(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}