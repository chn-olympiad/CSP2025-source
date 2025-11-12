#include<bits/stdc++.h>
#define rg register int
#define fo(i,l,r) for(rg i=(l);i<=(r);i++)
#define dfo(i,r,l) for(rg i=(r);i>=(l);i--)
#define fe(i,x) for(rg i=hd[x];i;i=nex[i])
#define frein freopen("in.txt","r",stdin)
#define freout freopen("out.txt","w",stdout)
#define fre(p) freopen(#p".in","r",stdin),freopen(#p".out","w",stdout)
#define vi vector<int>
#define eb emplace_back
#define pii pair<int,int>
#define fir first
#define sec second
#define mkp make_pair
#define i8 __int128
#define db double
#define ll long long
using namespace std;
bool deb=1,Mst;
void ck_(){cerr<<"\n";}
template<typename T,typename...R>
void ck_(T x,R...y){if(!deb)return;cerr<<x<<" ";ck_(y...);}
void Bz_(){cerr<<"---------------------------------\n";}
#define ck ck_
#define Bz Bz_()
#define outa(l,r,a) {fo(II,l,r)cerr<<a[II]<<" ";cerr<<"\n";}
#define gc() getchar()
inline void rd(int &x)
{
	int v(0),op(1);
	register char c=gc();
	while(c<'0'||'9'<c)c=gc();
	while('0'<=c&&c<='9')v=(v<<1)+(v<<3)+(c^48),c=gc();
	x=v*op; 
}
#define bit(x,y) ((x)>>(y)&1)
const int N=1e4+15,M=1e6+15;ll ans,s;
int n,m,k,c[N],b[N][15],x,y,t;
struct eg{int x,y,z;}a[M],d[M],f[1024][N];int la,ld,lf[1024];
int rr[N];
int find(int x){return x==rr[x]?x:rr[x]=find(rr[x]);}
ll MST(int n)
{
	fo(i,1,n)rr[i]=i;
	sort(a+1,a+1+la,[](eg a,eg b){return a.z<b.z;});
	int cnt=0,x,y;ll ans=0;
	ld=0;
	fo(i,1,la)
	{
		x=find(a[i].x),y=find(a[i].y);
		if(x!=y)
		{
			d[++ld]=a[i],ans+=a[i].z;
			rr[x]=y;
			if(++cnt==n-1)break;
		}
	}
	return ans;
}
bool Med;
int main()
{
//	frein;
	fre(road);
//	ck((&Mst-&Med)/1024.0);
	rd(n),rd(m),rd(k);la=m;
	fo(i,1,m)rd(a[i].x),rd(a[i].y),rd(a[i].z);
	fo(j,1,k)
	{
		rd(c[j]);
		fo(i,1,n)rd(b[i][j]);
	}
	ans=MST(n);//ck(ans);
	lf[0]=ld;
	fo(i,1,ld)f[0][i]=d[i];
	fo(o,1,(1<<k)-1)//if(o==1)
	{
		s=0,x=0,t=n;
		fo(i,1,k)if(bit(o,i-1))s+=c[i],x=i,t++;
		y=o^(1<<x>>1);
		la=lf[y];
		fo(i,1,la)a[i]=f[y][i];
		fo(i,1,n)a[++la]=eg{t,i,b[i][x]};
//		ck(la);
//		fo(i,1,la)ck(a[i].x,a[i].y,a[i].z);
		s+=MST(t),ans=min(ans,s);
//		ck(o,y,t,s);
		lf[o]=ld;
		fo(i,1,ld)f[o][i]=d[i];
	}
	cout<<ans;
	return 0;
}

















