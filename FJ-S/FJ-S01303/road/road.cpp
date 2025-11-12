#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+10,M=2e6+10;
struct node{
	int u,v,w;
	bool operator <(const node &x) const{
		return w<x.w;
	}
}a[M],b[M];
int n,m,k,f[N],w[12][N];
inline int read(){
	char c=getchar();
	int ans=0,f=1;
	while(c<48||c>57) (c==45?f=-1:1),c=getchar();
	while(c>=48&&c<=57) ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
}
int find(int x){
	if (f[x]==x) return x;
	return f[x]=find(f[x]);
}
inline int get(int n,int m){
	sort(a+1,a+m+1);
	for (int i=1;i<=n;i++) f[i]=i;
	int ans=0;
	for (int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if (find(u)^find(v)){
			ans+=w,f[find(u)]=find(v);
		}
	}
	return ans;
}
main(){
//	freopen("road4.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for (int i=1;i<=m;i++) b[i]={read(),read(),read()};
	sort(b+1,b+m+1);
	int mm=0;
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++){
		int u=b[i].u,v=b[i].v;
		if (find(u)^find(v)){
			f[find(u)]=find(v);
			b[++mm]={u,v,b[i].w};
		}
	}
	m=mm;
	for (int i=1;i<=k;i++)
		for (int j=0;j<=n;j++) w[i][j]=read();
	int ans=1e18;
	for (int i=0;i<(1<<k);i++){
		int np=n,mp=m,sum=0;
		for (int i=1;i<=m;i++) a[i]=b[i];
		int cnt=m;
		for (int j=0;j<k;j++) if ((i>>j)&1){
			np++,sum+=w[j+1][0],mp+=n;
			for (int l=1;l<=n;l++) a[++cnt]={np,l,w[j+1][l]};
		}
		ans=min(ans,sum+get(np,mp));
	//	for (int i=1;i<=m;i++)
	//		cout <<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<endl;
	//	for (int i=1;i<=cnt;i++)
	//		cout <<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
	//	puts("");
	//	cout <<np<<" "<<mp<<" "<<sum+get(np,mp)<<endl;
	}
	cout <<ans;
	return 0;
}

