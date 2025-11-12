#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+10,M=1e6+10,K=15;
ll fa[N+K];
ll read(){
	ll x=0;
	char s=getchar();
	for(;s>='0'&&s<='9';s=getchar())
		x=x*10+s-'0';
	return x;
}
void A(ll a){
	if(fa[fa[a]]!=fa[a])
		A(fa[a]);
	fa[a]=fa[fa[a]];
	return ;
}
struct tt{
	ll u,v,w;
};
tt x,y,t[2*M],t2[M];
bool X(tt a,tt b){
	return a.w<b.w;
}
ll top,top2,bot2=1;
void P(tt x){
	t[++top]=x;
	ll son=top;
	while(son/2>=1){
		ll fa=son/2;
		if(t[son].w>=t[fa].w)
			break;
		swap(t[son],t[fa]);
		son=fa;}
	return ;
}
void F(){
	t[1]=t[top--];
	ll fa=1;
	while(fa*2<=top){
		ll son=fa*2;
		if(son+1<=top&&t[son].w>=t[son+1].w)
			son++;
		if(t[son].w>=t[fa].w)
			break;
		swap(t[son],t[fa]);
		fa=son;}
	return ;
}
ll c[K],a[K][N];
ll n,m,k;
ll ans;
bool v[K];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
//	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		t2[++top2].u=read();
		t2[top2].v=read();
		t2[top2].w=read();}
	sort(t2+1,t2+top2+1,X);
	for(ll i=1;i<=k;i++){
		c[i]=read();
		x.u=i+n;
		for(ll j=1;j<=n;j++){
			a[i][j]=read();
			x.w=c[i]+a[i][j];
			x.v=j;
			P(x);}
	}
	for(ll i=1;i<=n+k;i++)
		fa[i]=i;
	ll l=n-1;
	while(l){
		if((t[1].w<t2[bot2].w)&&top>=1){
			y=t[1];
			F();}
		else{
			y=t2[bot2];
			bot2++;}
		A(y.u); A(y.v);
		if(fa[y.u]==fa[y.v])
			continue;
//		cout<<y.u<<" "<<y.v<<" "<<y.w<<endl;
		fa[fa[y.u]]=fa[y.v];
		ans+=y.w;
		if(y.u<=n){
			l--;
			continue;}
		if(v[y.u-n]==1){
			l--;
			continue;}
		v[y.u-n]=1;
		x.u=y.u;
		A(y.u);
		for(ll i=1;i<=n;i++){
			A(i);
			if(fa[y.u]==fa[i])
				continue;
			x.v=i;
			x.w=a[y.u-n][i];
			P(x);}
	}
	printf("%lld\n",ans);
	return 0;
}
