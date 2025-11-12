#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}

void file(){
    freoepn("club.in","r",stdin);
    freopen("club.out","w",stdout);
}

const int N=3e5+10;
int T,n,ans,num[4],vis[N];
struct node{
    int x,id,now,y;
    bool operator<(const node &i)const{
        return now>i.now;
    }
}a[N];

void solve(){
    n=read();
    ans=0;
    int now=0;
    for(int i=1;i<=3;i++)
        num[i]=n/2;
    for(int i=1;i<=n;i++)
        vis[i]=0;
    for(int i=1;i<=n;i++){
        int x=read(),y=read(),z=read();
        a[++now]={x,1,min(x-y,x-z),i};
        a[++now]={y,2,min(y-x,y-z),i};
        a[++now]={z,3,min(z-x,z-y),i};
    }
    sort(a+1,a+now+1);
    for(int i=1;i<=now;i++){
        if(vis[a[i].y] || !num[a[i].id]) continue;
        ans+=a[i].x;
        vis[a[i].y]=1;
        num[a[i].id]--;
    }
    cout<<ans<<"\n";
    return ;
}

signed main(){
    file();
    
    T=read();
    while(T--)
        solve();
    return 0;
}