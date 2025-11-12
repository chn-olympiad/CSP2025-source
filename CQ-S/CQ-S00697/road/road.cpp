#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
const int MM=1e6*3;
ll fa[MM];
ll head[MM];
struct node{
	ll w,f,t,nex; 
}c[MM];
ll cnt=0;
void asd(ll f,ll t,ll w){
	c[++cnt].f=f;
	c[cnt].t=t;
	c[cnt].w=w;
	c[cnt].nex=head[f];
	head[f]=cnt;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
ll find(ll x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	n=read(),m=read(),k=read();
	ll x,y,z;
	for(int i=1;i<=n;i++){
		head[i]=-1;
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		x=read(),y=read(),z=read();
		asd(x,y,z);
		asd(y,x,z);
	}
	ll ans=0,s=0;
	sort(c+1,c+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		ll x=find(c[i].f);
		ll y=find(c[i].t);
		if(x!=y){
			fa[x]=y;
			ans+=c[i].w;
			s++;
		}
		if(s==n-1)break;
	}
	write(ans);
	return 0;
} 
