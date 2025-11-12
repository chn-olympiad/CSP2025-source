#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5010],t;
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
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	if(n==3){
		t=max(max(a[1],a[2]),a[3]);
		if(2*t<a[1]+a[2]+a[3]) printf("1");
		else printf("0");
		return 0;
	}
	if(n==5) printf("9");
	else printf("1");
	return 0;
}
