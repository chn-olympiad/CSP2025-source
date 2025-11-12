#include<bits/stdc++.h>
#define reg register
#define int long long
inline int read(){
    reg int x=0,k=1; reg char ch=getchar();
    while (ch<'0'||ch>'9') (ch=='-')&&(k=-1),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*k; 
}
inline int min(reg int x,reg int y){return x<y?x:y;}
inline int max(reg int x,reg int y){return x>y?x:y;}
inline bool cmax(reg int &x,reg int y){return x<y?x=y,1:0;}
const int N=1e5+20,INF=1e18;
int n,m,a[N][3],mx[N],id[N];
inline void work(){
    n=read(); reg int ans=0;
    int cnt[3]={0,0,0};
    for (reg int i=1;i<=n;i++){
        mx[i]=-1,id[i]=i; reg int v=-INF;
        for (reg int j=0;j<3;j++){
            a[i][j]=read();
            if (v<a[i][j]) mx[i]=j,v=a[i][j];
        }
        // std::cerr<<"<< "<<v<<"\n";
        cnt[mx[i]]++,ans+=v;
    }
    reg int p=0;
    if (cnt[1]>cnt[p]) p=1; if (cnt[2]>cnt[p]) p=2;
    if (cnt[p]<=n>>1) return printf("%lld\n",ans),void();
    // std::cerr<<"qwq\n";
    std::vector<int> vc;
    for (reg int i=1;i<=n;i++) if (mx[i]==p){
        reg int v=-INF;
        for (reg int j=0;j<3;j++) if (j!=p){
            cmax(v,a[i][j]-a[i][p]);
        }
        // std::cerr<<"?? "<<v<<"\n";
        vc.push_back(v);
    }
    std::sort(vc.begin(),vc.end(),std::greater<int>());
    for (reg int i=1;i<=vc.size()-(n>>1);i++) ans+=vc[i-1];
    printf("%lld\n",ans);
}
signed main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    for (reg int _=read();_--;) work();
    return 0;
}