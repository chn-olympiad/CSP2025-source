//GZ-S00493 毕节梁才学校 韩昌辰 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll ret=0;
	char ch=' ',c=getchar();
	while(!('0'<=c&&c<='9')) ch=c,c=getchar();
	while('0'<=c&&c<='9') ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
	return ch=='-'?-ret:ret;
}
ll o,n,m,k,ans;
struct E{
	ll x,y,w;
};
E e[10000100];
bool v[1010];
ll tmp[1010];
bool cmp(E a,E b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(ll i=1;i<=10000010;i++) e[i].w=0x3f3f3f3f;
	memset(v,0,sizeof(v));
	n=read();
	m=read();
	k=read();
	for(ll i=1;i<=m;i++){
		ll a,b,ww;
		a=read();
		b=read();
		ww=read();
		e[i]=(E){a,b,ww};
	}
	o=m;
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=n;j++) tmp[j]=0;
		int c;
		c=read();
		for(ll j=1;j<=n;j++) tmp[j]=read();
		for(ll l=1;l<n;l++){
			for(ll r=l+1;r<=n;r++){
				ll ww=tmp[l]+tmp[r];
				o++;
				e[o]=(E){l,r,ww+c};
			} 
		}
	}
	sort(e+1,e+o+1,cmp);
	for(ll i=1;i<=o;i++){
		if(!v[e[i].x]||!v[e[i].y]){
			v[e[i].x]=true;
			v[e[i].y]=true;
			ans+=e[i].w;
		}
	}
	printf("%lld",ans);
	return 0;
}
