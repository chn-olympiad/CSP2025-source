#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
#define F(i,r,l) for(int i=r;i>=l;--i)
#define int long long
#define ULL unsigned long long
#define read(n) {int _x=0,_t=1;char _c=getchar();while(!isdigit(_c)){if(_c=='-')_t=-1;_c=getchar();}while(isdigit(_c))_x=_x*10+_c-'0',_c=getchar();n=_x*_t;}
using namespace std;
const int N=15005,M=1500005;
int n,m,k,b[11][N],cnt,fa[N],ok=0,res=LLONG_MAX;
struct node{
	int u,v,w;
	bool operator < (const node &a)const{
		return w<a.w;
	}
}a[M],l[M];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int solve(int OP){
	int ans=0,tot=0,num=0;
	f(i,1,m) l[i]=a[i];
	f(i,1,n+2*k) fa[i]=i;
	cnt=m;
	f(i,1,k){
		if((OP>>i-1)&1){
			++num;continue;
		}
		else{
			ans+=b[i][0];
			int fu=find(n+2*i-1),fv=find(n+2*i);
			if(fu==fv) continue;
			fa[fu]=fv;
			++tot;
			f(j,1,n){
				l[++cnt]=(node){n+2*i-1,j,b[i][j]};
				l[++cnt]=(node){n+2*i,j,b[i][j]};
			}
		}
	}
	sort(l+1,l+cnt+1);
	f(i,1,cnt){
		int fu=find(l[i].u),fv=find(l[i].v);
		if(fu==fv) continue;
		fa[fu]=fv;
		++tot;
		ans+=l[i].w; 
		if(tot==n+2*(k-num)-1) break;
	}
	return ans;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	f(i,1,m){
		read(a[i].u);read(a[i].v);read(a[i].w);
	}
	f(i,1,k){
		read(b[i][0]);
		if(b[i][0]) ok=1;
		f(j,1,n) read(b[i][j]);
		int opt=1;
		f(j,1,n) if(!b[i][j]) opt=0;
		ok|=opt;
	}
	if(!ok){
		printf("%lld\n",solve(0));
		return 0;
	}
	f(S,0,(1<<k)-1){
		res=min(res,solve(S));
	}
	printf("%lld\n",res);
	return 0;
}
