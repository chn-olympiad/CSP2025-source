#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
    return x*f;
}
const int N=1e5+10;
int T,n;
int a[N][5];
int ans,cnt[N],tot,t[5];
int max(int a,int b){
    return a>b ? a : b;
}
void work(int x){
    int tmp=max(max(a[x][1],a[x][2]),a[x][3]);
    ans+=tmp;
    if(tmp==a[x][1]) t[1]++;
    else if(tmp==a[x][2]) t[2]++;
    else t[3]++;
}
void work2(int x,int k){
    int tmp=max(max(a[x][1],a[x][2]),a[x][3]);
    if(tmp!=a[x][k]) return;
    if(tmp==a[x][1]) cnt[++tot]=a[x][1]-max(a[x][2],a[x][3]);
    else if(tmp==a[x][2]) cnt[++tot]=a[x][2]-max(a[x][1],a[x][3]);
    else cnt[++tot]=a[x][3]-max(a[x][1],a[x][2]);
}
void init(){
    ans=0;tot=0;
    t[1]=t[2]=t[3]=0;
    for(int i=1;i<=n;i++) cnt[i]=0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=read();
    while(T--){
        init();
        n=read();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                a[i][j]=read();
            }
            work(i);
        }
        if(max(max(t[1],t[2]),t[3])>n/2){
            int tmpp=max(max(t[1],t[2]),t[3]),k;
            if(tmpp==t[1]) k=1;
            else if(tmpp==t[2]) k=2;
            else k=3;
            for(int i=1;i<=n;i++) work2(i,k);
            sort(cnt+1,cnt+1+tot);
            for(int i=1;i<=max(max(t[1],t[2]),t[3])-n/2;i++) ans-=cnt[i];
        }
        cout<<ans<<'\n';
    }





    fclose(stdin);
    fclose(stdout);
}
