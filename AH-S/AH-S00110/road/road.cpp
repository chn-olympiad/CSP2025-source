#include<bits/stdc++.h>
#define rd read()
#define el putchar('\n')
#define QAQ printf("QAQ");
using namespace std;
typedef long long ll;

ll read(){
	char ch=getchar();
	ll x=0,flag=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			flag=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*flag;
}
void write(ll x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x<10){
		putchar(x+'0');
	}else{
		write(x/10);
		putchar(x%10+'0');
	}
}

const ll MAXN=1e4+5,MAXM=2e6+5,inf=1e18,mod=1e9+7;
ll n,m,k,ans;
struct ddd{
	ll u,v,w;
}a[MAXM];
vector<array<ll,2>> g[MAXN];
bool cmp(ddd a,ddd b){
	return a.w<b.w;
}
ll fa[MAXN],c[MAXN];
ll findfa(ll x){
	return (fa[x]==x)?x:x=findfa(fa[x]);
}
void solvek0(){
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(findfa(a[i].u)!=findfa(a[i].v)){
			fa[findfa(a[i].u)]=a[i].v;
			ans=ans+a[i].w;
		}
	}
	write(ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd,m=rd,k=rd;
	for(int i=1;i<=m;i++){
		a[i].u=rd,a[i].v=rd,a[i].w=rd;
	}
	if(k==0){
		solvek0();
		return 0;
	}
	for(int i=1;i<=k;i++){
		c[i]=rd;
		for(int j=1;j<=n;j++){
			a[++m].u=i;a[m].v=j;a[m].w=c[i]+rd;
		}
	}
	solvek0();
	return 0;
}
