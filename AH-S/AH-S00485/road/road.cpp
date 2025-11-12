#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);i++)
using namespace std;
//~ #define int long long
typedef long long LL;
const int M=10010;
int n,m,k;
struct edge{
	int from,to;
	LL w;
};
int fa[M];
LL c[15],a[15][M];
vector<edge> E;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int findfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=findfa(fa[x]);
}
inline LL read(){
	LL ans=0,f=1;
	char c=getchar_unlocked();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>=48&&c<=57){
		ans=ans*10+c-48;
		c=getchar_unlocked();
	}
	return ans*f;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	For(i,1,n) fa[i]=i;
	For(i,1,m){
		int u=read(),v=read();
		LL w=read();
		E.push_back({u,v,w});
	}
	For(i,1,k){
		c[i]=read();
		For(j,1,n){
			a[i][j]=read();
			For(l,1,j-1) E.push_back({l,j,a[i][j]+a[i][l]+c[i]});
		}
	}
	sort(E.begin(),E.end(),cmp);
	m=E.size();
	LL ans=0;
	int cnt=0;
	For(i,0,m-1){
		int u=E[i].from,v=E[i].to;
		int x=findfa(u),y=findfa(v);
		if(x!=y){
			fa[x]=y;
			ans+=E[i].w;
			cnt++;
		}
		if(cnt==m-1) break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
