#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<climits>
#define ll long long
using namespace std;
const int N=1e7+86;
const int F=20;
const int M=1e4+86;
ll n,m,k,ans;
struct T{
	ll u,v,wi;
};
struct T_T{
	ll wi,id;
};
T a[N]; 
ll cx[M],cy[M];
ll vil[F][N],to,nw; 
ll read(){
	ll x=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
bool cmp(T x,T y){
	return x.wi<y.wi;
}
ll fa[N];
ll find(ll x){
	if(fa[x]==x) return fa[x];
	fa[x]=find(fa[x]);
}
void unionn(ll x,ll y){
	fa[x]=y;
}
ll maxs;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		a[i].u=read(),a[i].v=read(),a[i].wi=read();
//		cx[a[i].u]=1;
//		cy[a[i].v]=1;
//		maxs=max(maxs,a[i].wi);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			vil[i][j]=read();
		}
	}
	for(int d=1;d<=k;d++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(i==j) continue;
//				if(vil[d][i]+vil[d][j]+vil[d][0]>maxs&&cx[i]&&cy[j]) continue;
				m++;
				a[m].u=i,a[m].v=j;
				a[m].wi=vil[d][i]+vil[d][j]+vil[d][0];
			}
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	stable_sort(a+1,a+1+m,cmp);
	ll cnt=0;
	for(int i=1;i<=m;i++){
		nw=a[i].u,to=a[i].v;
		ll r1=find(nw),r2=find(to);
		r1=fa[nw],r2=fa[to];
		if(r1!=r2){
			unionn(r1,r2);
			cnt++;
			ans+=a[i].wi;
		}
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans;
	return 0; 
} 

/*
 4 4 2
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4
 100 1 3 2 4
 
 
5 7 0
1 2 1
2 3 2
3 5 4
2 5 5
4 5 3
2 4 2
1 4 2
 */
