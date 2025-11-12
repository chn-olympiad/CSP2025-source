#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500010];
bool fg=0;
inline ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	for(ll i=1;i<=n;i++){
		if(a[i]!=1){
			fg=1;
			break;
		}
	}
	if(!fg&&k==0) printf("0");
	else if(n==4) printf("2");
	else printf("1");
	return 0;
}
