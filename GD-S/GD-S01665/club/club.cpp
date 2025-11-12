#include<iostream>
#include<string.h>
#include<map>
using namespace std;
#define LL long long
const int N=1e5+10,M=110;
LL T,n,d,i,j,k,f[M][M][M];
struct U{
	LL a,b,c;
}a[N];
//map<int,map<int,map<int,int> > > f;
LL dfs(LL ta,LL tb,LL tc){
	LL k=ta+tb+tc+1,x,y,z;
	if(~f[ta][tb][tc]) return f[ta][tb][tc];
	if(k>n) return 0;
	x=y=z=0;
	if(ta<d) x=dfs(ta+1,tb,tc)+a[k].a;
	if(tb<d) y=dfs(ta,tb+1,tc)+a[k].b;
	if(tc<d) z=dfs(ta,tb,tc+1)+a[k].c;
	return f[ta][tb][tc]=max(max(x,y),z);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
//		f.clear();
		memset(f,-1,sizeof(f));
		scanf("%lld",&n);
		d=n>>1;
		for(i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
		}
		printf("%lld\n",dfs(0,0,0));
	}
	return 0; 
}
