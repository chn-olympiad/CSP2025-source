#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define f(i,j,n) for(int i=j;i<=n;i++)
#define F(i,n,j) for(int i=n;i>=j;i--)
#define updmin(a,b) a=min(a,b)
#define updmax(a,b) a=max(a,b)
#define updsum(a,b) a=(a+(b))%mod
#define updtim(a,b) a=a*(b)%mod
using namespace std;
typedef pair<int,int> pii;
namespace fsd{
    const int MX=1<<20;
    char buf[MX],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MX,stdin),p1==p2)?EOF:*p1++)
    inline int read(){
        int ak=0,csp=1;
        char c=gc();
        while(!isdigit(c)){if(c=='-')csp=-1;c=gc();}
        while(isdigit(c))ak=ak*10+c-'0',c=gc();
        return ak*csp;
    }
}
using namespace fsd;
const int N=1e4+10;
int n,m,K;
int ok[11],c[N];
pii a[11][N];
struct edg{int l,r,v;}ed[N*100],edw[N*11],edt[N];
int fath[N+20],siz[N+20];
int getfa(int k){return k==fath[k]?k:fath[k]=getfa(fath[k]);}
bool M(int a,int b){
    int aa=getfa(a),bb=getfa(b);
    if(aa!=bb){
    	if(siz[aa]>siz[bb])swap(aa,bb);
        fath[aa]=bb;
        siz[bb]=max(siz[bb],siz[aa]+1);
        return 1;
    }
    return 0;
}
edg edh[N*11];
edg* o[12];
int ln[12];
void merge(edg *a,int n,edg *b,int m){
	int ct=1,ct1=1,cc=0;
	while(ct<=n&&ct1<=m){
//		cout<<ct<<":"<<ct1<<endl;
		if(a[ct].v<b[ct1].v)edh[++cc]=a[ct],ct++;
		else edh[++cc]=b[ct1],ct1++;
	}
	while(ct<=n)edh[++cc]=a[ct],ct++;
	while(ct1<=m)edh[++cc]=b[ct1],ct1++;
	f(i,1,cc)a[i]=edh[i];
}
void merge(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	merge(l,mid),merge(mid+1,r);
	merge(o[l],ln[l],o[mid+1],ln[mid+1]);
	ln[l]+=ln[mid+1];
}
void gs(){
    n=read(),m=read(),K=read();
    f(i,1,m)ed[i].l=read(),ed[i].r=read(),ed[i].v=read();
    f(i,1,K){
        ok[i]=read();
        f(j,1,n)a[i][j]={read(),j};
        sort(a[i]+1,a[i]+1+n);
    }
    sort(ed+1,ed+1+m,[&](edg a,edg b){return a.v<b.v;});
    int ct=0;
    ll tot=0;
    f(i,1,n)fath[i]=i,siz[i]=1;
    f(i,1,m){
        if(M(ed[i].l,ed[i].r))tot+=ed[i].v,edt[++ct]=ed[i];
    }
    ll ans=tot;
    f(i,1,(1<<K)-1){
        int ctt=ct;
        f(j,1,ct)edw[j]=edt[j];
        ll thi=0;
        ctt=ct;
        o[0]=edw,ln[0]=ct;
        int r=0;
        f(j,1,K){
            if(i>>j-1&1){
            	o[r+1]=o[r]+ln[r],ln[++r]=n;
                thi+=ok[j];
                f(t,1,n)edw[++ctt]={a[j][t].second,j+n,a[j][t].first};
            }
        }
//        cout<<i<<endl;
        merge(0,r);
//        sort(edw+1,edw+1+ctt,[&](edg a,edg b){return a.v<b.v;});
        f(j,1,n+K)fath[j]=j,siz[j]=1;
        f(j,1,ctt)if(M(edw[j].l,edw[j].r))thi+=edw[j].v;
        updmin(ans,thi);
//        continue;
    }
    printf("%lld\n",ans);
}
//  #define DXN
signed main(){
    // freopen("rd.out","r",stdin);
#ifndef DXN
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
#endif
#ifdef NXD
    int t=read();while(t--)
#endif
    gs();
    return 0;
}
/*
59848765384
*/
