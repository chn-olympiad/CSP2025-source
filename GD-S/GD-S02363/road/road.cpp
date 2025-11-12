#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+7;
void in(ll &num){
	ll k=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k=k*10+c-'0';
		c=getchar();
	}
	num=k*f;
}
void out(ll num){
	if(num<0){
		putchar('-');
		num*=-1;
	}
	if(num<10){
		putchar(num+'0');
	}else{
		out(num/10),putchar(num%10+'0');
	}
}
ll f[N],m,n,po,k,a[13][N],c[13];
struct node{
	ll dis,u,v;
	inline bool operator <(const node &x) const {
		return dis<x.dis;
	}
}e[200*N];
ll find(ll x){
	if(f[x]!=x){
		f[x]=find(f[x]);
	}
	return f[x];
}
node cd[N];
ll krusal(bool ok){
	ll ans=0,ls=0;
	for(ll i=1;i<=n+k;i++){
		f[i]=i;
	}
	ll cnt=n+po*n-1;
	if(ok){
		cnt=m;
	}
	sort(e+1,e+cnt+1);
//	out(cnt);
//	putchar('\n');
	for(ll i=1;i<=cnt;i++){
		ll u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)){
			f[u]=f[v];
			ans+=e[i].dis;
			ls++;
//			out(e[i].dis);
//			putchar(' ');
//			out(u);
//			putchar(' ');
//			out(v);
//			putchar('\n');
			if(ok){
				cd[ls]=e[i];
			}
		}
		if(ls==n+po-1){
			break;
		}
	}
	for(ll i=1;i<=n-1;i++){
		e[i]=cd[i];
	}
//	out(ans);
	return ans;
}
ll cont,use[13],minn=1e18,t;
void dfs(ll now){
	if(now==k+1){
		ll sum=n-1;
		for(ll i=1;i<=k;i++){
//			out(use[i]);
//			putchar(' ');
			if(use[i]){
				for(ll j=1;j<=n;j++){
					e[++sum].dis=a[i][j];
					e[sum].u=i+n;
					e[sum].v=j;
				}
			}
		}
//		putchar('\n');
		ll ls;		
		if(cont==0){
			ls=t+krusal(1);
			minn=min(minn,ls);
			cont++;
		}else{
			ls=t+krusal(0);
			minn=min(minn,ls);
		}
//		out(ls);
//		putchar('\n');
		return;
	}
	use[now]=0;
	dfs(now+1);
	use[now]=1;
	t+=c[now];
	po++;
	dfs(now+1);
	use[now]=0;
	po--;
	t-=c[now];
}
string ls="road3";
string s=ls+".in";
string tl=ls+".out";
string oui=ls+".ans";
bool flag=1;
int main(){
//	freopen(s.c_str(),"r",stdin);
//	freopen(tl.c_str(),"w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	in(n),in(m),in(k);
	for(ll i=1;i<=m;i++){
		in(e[i].u),in(e[i].v),in(e[i].dis);
	}
	for(ll i=1;i<=k;i++){
		in(c[i]);
		for(ll j=1;j<=n;j++){
			in(a[i][j]);
			if(a[i][j]!=0){
				flag=0;
			}
		}
	}
	if(!flag){
		dfs(1);
		out(minn);
	}else{
		out(0);
	}
	return 0;
//	system(a.c_str());
//	system("pause");
//	return 0;	
}
/*
5 7 2
1 4 3
1 5 7
4 5 2
4 3 8
3 5 4
2 5 3
4 2 3
2 3 2 2 1 2
0 1 2 1 3 1
*/
