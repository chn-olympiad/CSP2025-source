#include<bits/stdc++.h>
#define re register
#define N 10005
#define M 1000005
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
int n,m,k,f[N],rep[N],tot;
struct node{
	int u,v,w;
}tr[M+10*N];
inline int find(int p){
	return f[p]==p?p:f[p]=find(f[p]);
}
inline bool cmp(node P,node Q){
	return P.w<Q.w;
}
long long ans;
bool chk;
int cnt;
int main(){
//	freopen("road3.in","r",stdin);
//	freopen("road3.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(re int i(1);i<=n;++i)f[i]=i;
	if(k==0){
		for(re int i(1);i<=m;++i){
			tr[i].u=read();
			tr[i].v=read();
			tr[i].w=read();
		}
		sort(tr+1,tr+m+1,cmp);
		for(re int i(1);i<=m;++i){
			int u=tr[i].u,v=tr[i].v;
			if(find(u)!=find(v)){
				f[find(u)]=find(v);
				ans+=tr[i].w;
				if(++cnt==n-1)break;
			}
		}
		cout<<ans;
	}
	else{
		chk=1;
		for(re int i(1);i<=m;++i){
			tr[i].u=read();
			tr[i].v=read();
			tr[i].w=read();
		}
		for(re int i(1);i<=k;++i){
			int c=read();
			if(c!=0)chk=0;
			int pos=0;
			for(re int j(1);j<=n;++j){
				rep[j]=read();
				if(rep[j]==0)pos=j;
			}
			for(re int j(1);j<=n;++j){
				if(j==pos)continue;
				++tot;
				tr[m+tot].u=pos;
				tr[m+tot].v=j;
				tr[m+tot].w=rep[j];
			}
		}
		if(chk){
			sort(tr+1,tr+tot+m+1,cmp);
			for(re int i(1);i<=m+tot;++i){
				int u=tr[i].u,v=tr[i].v;
				if(find(u)!=find(v)){
					f[find(u)]=find(v);
					ans+=tr[i].w;
					if(++cnt==n-1)break;
				}
			}
			cout<<ans;
		}
	}
}

