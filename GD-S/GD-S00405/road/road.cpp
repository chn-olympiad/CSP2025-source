#include<bits/stdc++.h>
using namespace std;
const long long inf=1000000000000000000;
int n,m,k;
long long c[20];
long long a[20][10010];
int cnt[20],can[20][10010];
int fa[20010];
int l[1050][20],tol[1050];
set<pair<long long,pair<int,int> > >se;
int getfather(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=getfather(fa[x]); 
}
int read(){
	int res=0;
	char ch;
	while(1){
		ch=getchar();
		if(ch<'0'||ch>'9')break;
		res=res*10+(ch-'0');
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(register int i=1;i<=m;++i){
		int u,v,w;
		u=read();
		v=read();
		w=read();
		se.insert(make_pair(w,make_pair(u,v)));
	}
	for(register int i=1;i<=k;++i){
		c[i]=read();
		for(register int j=1;j<=n;++j){
			a[i][j]=read();
//			se[++m]=(data){}
		}
	}
	
	int ln=(1<<(k))-1;
	for(register int s=1;s<=ln;++s)
		for(register int i=1;i<=k;++i)
			if((1<<(i-1))&s)
				l[s][++tol[s]]=i;
	long long ans=inf;
	for(register int s=1;s<=k;++s){
		long long res=0ll;
		for(register int i=1;i<=n+k;++i)
			fa[i]=i;
		int nd=n+1;
		res+=c[s];
		for(int j=1;j<=n;++j){
			se.insert(make_pair(a[s][j],make_pair(j,n+s)));
		}
		int tot=0;
		for(auto x:se){
			int u=x.second.first,v=x.second.second;
			long long w=x.first;
//			printf("%d %d %lld\n",u,v,w);
			int fx=getfather(u),fy=getfather(v);
			if(fx==fy)continue;
			if(v>n)
				can[s][++cnt[s]]=u;
			fa[fx]=fy;
//			printf("%d %d\n",fx,sum[fx]);
			res+=w;
			tot++;
			if(tot==nd-1){
//				printf("?");
				break;
			}
		}
		ans=min(ans,res);
		for(int j=1;j<=n;++j){
			se.erase(make_pair(a[s][j],make_pair(j,n+s)));
		}
//		printf("    %d %lld\n",s,res);
	}
//	for(int i=1;i<=k;++i){
//		for(int j=1;j<=cnt[i];++j)
//			printf("%d ",can[i][j]);
//		printf("\n");
//	}
//	printf("%lld\n",ans);
	// how?

	for(int s=0;s<=ln;++s){
		long long res=0ll;
		for(int i=1;i<=n+k;++i)
			fa[i]=i;
		int nd=n+tol[s],flag=0;
		for(int i=1;i<=tol[s];++i){
			int x=l[s][i];
			res+=c[x];
			if(!cnt[x]){
				flag=1;
				break;
			}
			for(int j=1;j<=cnt[x];++j)
				se.insert(make_pair(a[x][can[x][j]],make_pair(can[x][j],n+x)));
		}
		if(flag)continue;
		int tot=0;
		for(auto x:se){
			int u=x.second.first,v=x.second.second;
			long long w=x.first;
//			printf("%d %d %lld\n",u,v,w);
			int fx=getfather(u),fy=getfather(v);
			if(fx==fy)continue;
			fa[fx]=fy;
//			printf("%d %d\n",fx,sum[fx]);
			res+=w;
			tot++;
			if(tot==nd-1){
//				printf("?");
				break;
			}
		}
		ans=min(ans,res);
		for(int i=1;i<=tol[s];++i){
			int x=l[s][i];
			for(int j=1;j<=cnt[x];++j)
				se.erase(make_pair(a[x][can[x][j]],make_pair(can[x][j],n+x)));
		}
//		printf("    %d %lld\n",s,res);
	}
	printf("%lld",ans);
	return 0;
}
