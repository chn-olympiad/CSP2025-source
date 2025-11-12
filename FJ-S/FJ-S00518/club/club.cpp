#include <bits/stdc++.h>
using namespace std;
using tp=long long;
#define For(i,l,r) for(tp i(l),i##sc03(r);i<=i##sc03;++i)
#define FoR(i,r,l) for(tp i(r),i##sc03(l);i>=i##sc03;--i)
#define ALL(G) G.begin(),G.end()
#define SIZ(G) tp(G.size())
#define pb emplace_back
#define pf emplace_front
#define ep emplace
#define gp make_pair
#define fr first
#define sd second
inline tp read(){
    tp x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9')ch=='-'?f=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();return x*f;
}inline bool write(tp x,char ch='\n'){return printf("%lld",x),putchar(ch),true;}
template<class T>inline T Max(T a,T b){return a>b?a:b;}
template<class T>inline T Min(T a,T b){return a<b?a:b;}
template<class T,class Q>inline bool Cmax(T&a,Q b){return a<b?a=b,true:false;}
template<class T,class Q>inline bool Cmin(T&a,Q b){return a>b?a=b,true:false;}
const tp N=1000100;
tp t,n;
struct Query{
    tp x[4];tp ind;
    friend bool operator < (Query a,Query b){
        return Max(Max(a.x[1],a.x[2]),a.x[3])<Max(Max(b.x[1],b.x[2]),b.x[3]);
    }
}A[N],a[N],b[N];
struct Qry{
    tp x,ind;
}tmp[4];
tp cnt[4],pos[N],ID[N];
bool cmpsub(Query a,Query b){
    tp mxa=Max(Max(a.x[1],a.x[2]),a.x[3]),mna=Min(Min(a.x[1],a.x[2]),a.x[3]);
    tp mxb=Max(Max(b.x[1],b.x[2]),b.x[3]),mnb=Min(Min(b.x[1],b.x[2]),b.x[3]);
    tp sda=a.x[1]+a.x[2]+a.x[3]-mxa-mna,sdb=b.x[1]+b.x[2]+b.x[3]-mxb-mnb;
    return mxa-sda>mxb-sdb;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    For(kkk,1,t){
        // cerr<<"Case: "<<kkk<<'\n';
        n=read();
        tp ans=0;
        For(i,1,3)cnt[i]=0;
        For(i,1,n)a[i].x[1]=read(),a[i].x[2]=read(),a[i].x[3]=read(),a[i].ind=i,pos[i]=0,ID[i]=0;
        For(i,1,n)For(j,1,3)A[i].x[j]=a[i].x[j];
        sort(a+1,a+n+1);reverse(a+1,a+n+1);
        // For(i,1,n){For(j,1,3)cerr<<a[i].x[j]<<' ';cerr<<'\n';}
        For(i,1,n){
            For(j,1,3)tmp[j].x=a[i].x[j],tmp[j].ind=j;
            sort(tmp+1,tmp+4,[&](Qry a,Qry b){return a.x>b.x;});
            // cerr<<tmp[1].ind<<' ';
            // For(j,1,3){cerr<<a[i].x[j]<<' ';}cerr<<'\n';
            ++cnt[tmp[1].ind];
        }
        tp mx=Max(Max(cnt[1],cnt[2]),cnt[3]);
        if(mx<=n/2){
            For(i,1,n){
                For(j,1,3)tmp[j].x=a[i].x[j],tmp[j].ind=j;
                sort(tmp+1,tmp+4,[&](Qry a,Qry b){return a.x>b.x;});
                ans+=tmp[1].x;
            }
            write(ans);
            continue;
        }
        tp mxind=0;
        For(i,1,3)if(cnt[i]==mx){mxind=i;break;}
        For(i,1,n){
            For(j,1,3)tmp[j].x=a[i].x[j],tmp[j].ind=j;
            sort(tmp+1,tmp+4,[&](Qry a,Qry b){return a.x>b.x;});
            if(tmp[1].ind!=mxind)ans+=tmp[1].x;/*,cerr<<tmp[1].x<<'\n'*/
            // else ans+=tmp[2].x;
        }
        For(i,1,n)For(j,1,3)b[i].x[j]=A[i].x[j];
        sort(b+1,b+n+1,cmpsub);tp mxcnt=0;
        For(i,1,n){
            For(j,1,3)tmp[j].x=b[i].x[j],tmp[j].ind=j;
            sort(tmp+1,tmp+4,[&](Qry a,Qry b){return a.x>b.x;});
            // cerr<<tmp[1].ind<<' '<<mxind<<' ';
            // For(j,1,3){cerr<<b[i].x[j]<<' ';}cerr<<'\n';
            if(tmp[1].ind==mxind){
                // ans-=tmp[2].x;
                if(mxcnt!=n/2){
                    ans+=tmp[1].x;
                    ++mxcnt;//cerr<<tmp[1].x<<'\n';
                }
                else ans+=tmp[2].x;
            }
        }
        write(ans);
    }
    return 0;
}