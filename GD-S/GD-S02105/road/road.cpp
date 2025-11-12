#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
const int M=1e6+5;
long long n,m,k,ans=1e18,cnt,tot;
struct wbx{
	long long x,y,v;	
}E[M],e[M];
struct FZY{
	long long c,b[N];
}a[15];
void add(long long x,long long y,long long v){e[++cnt]={x,y,v};}
long long R[N];
long long Find(long long x){return R[x]==x?x:R[x]=Find(R[x]);}
bool cmp(wbx x,wbx y){
	return x.v<y.v;
}
void Dij(long long fzy,long long z,bool bj,long long x){
	long long t=0,s=x;
	sort(E+1,E+1+fzy,cmp);
	for(int i=1;i<=fzy;i++)
		R[i]=i;
	for(int i=1;i<=fzy;i++)
		if(Find(E[i].x)!=Find(E[i].y)){
			t++,s+=E[i].v,R[Find(E[i].x)]=Find(E[i].y);
			if(bj==1) add(E[i].x,E[i].y,E[i].v);
			if(t==z-1){
				ans=min(ans,s);
				return;
			}
		}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>E[i].x>>E[i].y>>E[i].v;
	Dij(m,n,1,0);
	for(int i=1;i<=k;i++){
		cin>>a[i].c;
		for(int j=1;j<=n;j++)
			cin>>a[i].b[j];
	}
	long long x=0,t=0;
	for(int i=1;i<(1<<k);i++){
		tot=n-1,x=0,t=0;
		for(int j=1;j<=n-1;j++) E[j]=e[j];
		for(int j=1;j<=k;j++){
			if(1<<(j-1) & i){
				t++,x+=a[j].c;
				for(int k=1;k<=n;k++) E[++tot]={j+n,k,a[j].b[k]};
			}
		}
		Dij(tot,t+n,0,x);
	}
	cout<<ans;
	return 0;
}
/*
初一的时候我们语文老师开学就让我们写一篇作文：是否喜欢语文？为何喜欢语文？
现在问问自己， 是否喜欢OI？为何喜欢OI？
在平时，我可能会不假思索地回答肯定不喜欢。
诚然，OI很累，不止OI，竞赛都很累。 
*/
