#include<bits/stdc++.h>
using namespace std;
namespace umrofcen{
	int n,m,k,i,j,J,K,x,y,X,Y,u,v,w,z,f[10101],l[1050],p[1050][10101];long long s,t,c[1050];struct E{int u,v,w;E(){}E(int a,int b,int c){u=a,v=b,w=c;}bool operator<(E x)const{return w<x.w;}}e[1501501];
	int _(int x){return f[x]^f[f[x]]?f[x]=_(f[x]):f[x];}
	void M(){
		for(cin>>n>>m>>k;z^m;cin>>e[z].u>>e[z].v>>e[z].w)++z;
		for(i=0,std::sort(e+1,e+m+1);i^k;std::sort(e+m+i*n+1,e+m+i*n+n+1),++i)for(j=0,cin>>c[1<<i];j^n;e[++z]=E(i+n+1,++j,w))cin>>w;
		for(i=n+k;i;--i)f[i]=i;
		for(i=s=0;i++^m;)if((u=_(e[i].u))^(v=_(e[i].v)))f[u]=v,s+=e[p[0][++l[0]]=i].w;
		for(i=0;!(++i>>k);s>t?s=t:0){
			for(j=n+k;j;--j)f[j]=j;
			for(K=__builtin_ctz(i),J=i&i-1,t=c[i]=c[i&-i]+c[J],x=1,X=l[J],y=m+K*n+1,Y=y+n-1;x<=X&&y<=Y;)
				if(j=y>Y||(x<=X&&e[p[J][x]]<e[y])?p[J][x++]:y++,(u=_(e[j].u))^(v=_(e[j].v)))f[u]=v,t+=e[p[i][++l[i]]=j].w;
		}
		cout<<s;
	}
};
int main(){return freopen("road.in","r",stdin),freopen("road.out","w",stdout),cin.tie(nullptr),ios::sync_with_stdio(false),umrofcen::M(),0;}
