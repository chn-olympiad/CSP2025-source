#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXM 1000005
#define int long long
int n,m,k;
struct edge{
	int u,v,w;
	bool operator < (const edge a){
		return w<a.w;
	}
}e[MAXM<<2],s[MAXM<<1];int tot=0,len=0;
int a[15][10005];
int f[10050];
int find(int x){
	if(x==f[x]) return x;
	else return find(f[x]);
}
int Kruskal(int t,bool chk=false){
//	cout<<"$$$";
	int ans=0;len=0;
	sort(e+1,e+tot+1);
//	cout<<"$$$";
	int sum=1,pos=0;
	while(sum<n+t){
		++pos;
		int fu=find(e[pos].u);
		int fy=find(e[pos].v);
		if(fu!=fy){
			ans+=e[pos].w;
			sum++;
			f[fu]=fy;
			s[++len]=e[pos];
//			cout<<e[pos].u<<' '<<e[pos].v<<' '<<e[pos].w<<'\n';
		}
	}return ans;
}int c[15];
void read(int &x){
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		int u,v,w;read(u),read(v),read(w);
		s[++tot].u=u,s[tot].v=v,s[tot].w=w;
		e[tot]=s[tot];
//		s[++tot].u=v,s[tot].v=u,s[tot].w=w;
	}
	for(int j=1;j<=k;j++){
		read(c[j]);
		for(int i=1;i<=n;i++) read(a[j][i]);
	}len=tot;
//	cout<<"###";
		for(int j=1;j<=n+k+10;j++) f[j]=j;
	int ans=Kruskal(0,true);
//	cout<<ans;
	for(int tmp=1;tmp<(1<<k);tmp++){
		tot=len;
		for(int i=1;i<=len;i++) e[i]=s[i];
		for(int j=1;j<=n+k+10;j++) f[j]=j;
		int t=0,g=0;
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&tmp){t++;g+=c[j];
				for(int i=1;i<=n;i++){
					e[++tot].u=i,e[tot].v=n+j,e[tot].w=a[j][i];
//					e[++tot].u=n+j,e[tot].v=i,e[tot].w=a[j][i];
				}
			}
		}
		g+=Kruskal(t);
		ans=min(ans,g);
//		cout<<tmp<<':'<<g<<' '<<t<<endl;
	}cout<<ans<<'\n';
	return 0;
}
