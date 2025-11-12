#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,flag=0; char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') flag=1; c=getchar();}
    while(c>='0' && c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return flag ? ~(x-1) : x;
}

const int N=1e5+5;
int t,n;
int a[N][3];
int cnt[3];
ll ans;
int v[N],top;

inline int getmxp(int i){
    int res=0;
    for(int j=0; j<3; j++)
        if(a[i][j]>a[i][res])
            res=j;
    return res;
}

inline int getcxp(int i){
    int p=getmxp(i);
    int res=114514;
    for(int j=0; j<3; j++){
        if(j==p) continue;
        if(res==114514) res=j;
        else if(a[i][j]>a[i][res]) res=j;
    }
    return res;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=read();
    while(t--){
        n=read();
        ans=cnt[0]=cnt[1]=cnt[2]=top=0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<3; j++)
                a[i][j]=read();
            int p=getmxp(i),q=getcxp(i);
            ans+=a[i][p];
            cnt[p]++;
        }
        int p=114;
        for(int i=0; i<3; i++)
            if(cnt[i]>(n>>1))
                p=i;
        if(p!=114){
            for(int i=1; i<=n; i++)
                if(getmxp(i)==p)
                    v[++top]=a[i][p]-a[i][getcxp(i)];
            sort(v+1,v+top+1);
            int d=cnt[p]-(n>>1);
            for(int i=1; i<=d; i++) ans-=v[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
