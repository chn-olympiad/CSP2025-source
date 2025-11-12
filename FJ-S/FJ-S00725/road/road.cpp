#include <bits/stdc++.h>
using namespace std;
int read(){
	int res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9')
		res=res*10+ch-'0',ch=getchar();
	return res;
}
const int N=10100,M=1000100,K=15;
using ll=long long;
int n,m,k,f[N],b[K],idx[K],siz[K];
array<int,3> e[M],c[K][N];
vector<int> one;
ll ans=LLONG_MAX;
int find(int id){
	return f[id]=(id==f[id]?id:find(f[id]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		e[i][1]=read(),e[i][2]=read(),e[i][0]=read();
	sort(e+1,e+m+1);		
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1,tot=0;i<=m;i++){
		int f1=find(e[i][1]),f2=find(e[i][2]);
		if(f1!=f2) f[f1]=f2,c[0][++siz[0]]=e[i]; 
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i]);
		for(int j=1,v;j<=n;j++)
			scanf("%d",&v),c[i][++siz[i]]={v,n+i,j};
		sort(c[i]+1,c[i]+siz[i]+1);
	}
	for(int t=0;t<(1<<k);t++){
		one={0};
		int es=n;
		ll sum=0;
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=0;i<=k;i++) idx[i]=1;
		for(int i=1;i<=k;i++) if(t>>(i-1)&1)
			sum+=b[i],one.push_back(i),es++;
		for(int i=1;i<es;i++){
			array<int,3> add={INT_MAX,0,0};
			for(auto id:one) if(idx[id]<=siz[id])
				add=min(add,c[id][idx[id]]);
			int f1=find(add[1]),f2=find(add[2]);
			f[f1]=f2,sum+=add[0];
			for(auto id:one)
				while(idx[id]<=siz[id]&&find(c[id][idx[id]][1])==find(c[id][idx[id]][2])) idx[id]++;
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
}
