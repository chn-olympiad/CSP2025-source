#include<cstdio>
#include<algorithm>
const int N=1e5+10,_N=210;
int T,n;
int ans;
int a[N],b[N],c[N];
int p[N];
int f[_N][_N],g[_N][_N];
/*
int ans,ov,ov2,omv;
int og[N][3];
int tot[3];
struct Node{
	int t[3],id,mx;
	Node(int a=0,int b=0,int c=0,int i=0){t[0]=a,t[1]=b,t[2]=c,id=i,mx=0,t[mx]<t[1]?mx=1:0,t[mx]<t[2]?mx=2:0;}
}p[N],P[3][N];
*/
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')ch=='-'?f=0:0,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?x:-x;
}
template<typename T>inline T max(T a,T b){return a>b?a:b;}
/*
inline void solve(){
	n=read(),ans=0,ov=ov2=n+1,tot[0]=tot[1]=tot[2]=0;
	for(int i=1;i<=n;++i)
		og[i][0]=read(),og[i][1]=read(),og[i][2]=read(),
		p[i]=Node(og[i][0]-og[i][1],og[i][1]-og[i][2],og[i][2]-og[i][0],i);
	std::sort(p+1,p+n+1,[](const Node &a,const Node &b){return a.t[a.mx]>b.t[b.mx];});
	for(int i=1;i<=n;++i){
		if(tot[p[i].mx]<n/2)P[p[i].mx][++tot[p[i].mx]]=p[i].id,ans+=og[p[i].id][p[i].mx];//,printf("%d\n",og[p[i].id][p[i].mx]);
		else{ov=i;break;}
	}
	omv=p[ov].mx;
	for(int i=ov;i<=n;++i)
		if(p[i].mx==omv){
			if(omv==0)p[i].mx=(p[i].t[1]>p[i].t[2]?1:2);
			if(omv==1)p[i].mx=(p[i].t[0]>p[i].t[2]?0:2);
			if(omv==2)p[i].mx=(p[i].t[0]>p[i].t[1]?0:1);
		}
	std::sort(p+ov,p+n+1,[](const Node &a,const Node &b){return a.t[a.mx]>b.t[b.mx];});
	for(int i=ov;i<=n;++i){
		if(tot[p[i].mx]<n/2)P[p[i].mx][++tot[p[i].mx]]=p[i].id,ans+=og[p[i].id][p[i].mx];//,printf("%d\n",og[p[i].id][p[i].mx]);
		else{ov2=i;break;}
	}
	for(int i=ov2;i<=n;++i)
		for(int j=0;j<=2;++j)if(j!=omv&&j!=p[ov2].mx)
			ans+=og[p[i].id][j];//,printf("%d %d %d\n",p[i].id,j,og[p[i].id][j]);
	printf("%d\n",ans);
//	for(int i=1;i<=n;++i)if(p[i].a-p[i].b<=0){
//		pos=i-1;
//		break;
//	}
//	for(int i=1;i<=pos;++i)
}
*/
inline void spA(){
	std::sort(a+1,a+n+1,[](const int &a,const int &b){return a>b;});
	for(int i=1;i<=n/2;++i)
		ans+=a[i];
	printf("%d\n",ans);
}
inline void spB(){
	for(int i=1;i<=n;++i)p[i]=i;
	std::sort(p+1,p+n+1,[](const int &u,const int &v){return a[u]-b[u]>a[v]-b[v];});
	for(int i=1;i<=n/2;++i)
		ans+=a[p[i]];
	for(int i=n/2+1;i<=n;++i)
		ans+=b[p[i]];
	printf("%d\n",ans);
}
inline void solve(){
	n=read(),ans=0;bool spa=1,spb=1;
	for(int i=1;i<=n;++i)
		a[i]=read(),b[i]=read(),c[i]=read(),spa&=(b[i]==0&&c[i]==0),spb&=(c[i]==0);
	if(spa)return spA();
	if(spb)return spB();
	for(int i=0;i<=n/2;++i)for(int j=0;j<=n/2;++j)
		f[i][j]=g[i][j]=0;
	for(int l=1;l<=n;++l){
		for(int i=0;i<=n/2&&i<=l;++i)for(int j=0;j<=n/2&&j<=l;++j)if(i+j<=l&&l-i-j<=n/2)
			g[i][j]=max(i?f[i-1][j]+a[l]:0,max(j?f[i][j-1]+b[l]:0,l-1-i-j>=0?f[i][j]+c[l]:0));//,printf("%d %d %d %d\n",l,i,j,g[i][j]);
		for(int i=0;i<=n/2&&i<=l;++i)for(int j=0;j<=n/2&&j<=l;++j)if(i+j<=l&&l-i-j<=n/2)
			f[i][j]=g[i][j];
	}
	for(int i=0;i<=n/2;++i)for(int j=0;j<=n/2;++j)
		if(n-i-j<=n/2)ans=max(ans,f[i][j]);
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	T=read();
	while(T--)solve();
	return 0;
}
/*
Ren5Jie4Di4Ling5%

15:24
For special B: a[i]-b[i]>a[j]-b[j] -> i \in A,j \in B 
15:33
For all, half in A, half in B;
A: a<c to C,B the same.

16:47
70 pts

*/
