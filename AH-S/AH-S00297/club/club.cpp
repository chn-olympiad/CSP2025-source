#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define pr pair<int,int>
using namespace std;
template<typename T>void in(T &x){
    char c=getchar();int f=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-'){c=getchar();f=-1;}
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    x*=f;
}
template<typename T>T mn(T a,T b){return a<b?a:b;}
template<typename T>T mx(T a,T b){return b<a?a:b;}
const int N=1e5+5,inf=1e9+7;
int n,a[N][3],b[N],id[N];
vector<int> V[3];
bool cmp(int x,int y){return b[x]>b[y];}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;in(T);
    while(T--){
        in(n);
        for(int j=0;j<3;++j) V[j].clear();
        ll ans=0;
        for(int i=1;i<=n;++i){
            b[i]=0;
            for(int j=0;j<3;++j) in(a[i][j]),b[i]=mx(b[i],a[i][j]);
            id[i]=i;
        }
        sort(id+1,id+1+n,cmp);
        for(int i=1;i<=n;++i){
            ans+=b[id[i]];
            int now=0,z=-inf;
            for(int j=0;j<3;++j) if(a[id[i]][j]==b[id[i]]){now=j;break;}
            for(int j=0;j<3;++j) if(j^now) z=mx(z,a[id[i]][j]);
            V[now].push_back(z-a[id[i]][now]);
        }
        int now=-1;
        for(int j=0;j<3;++j) if(V[j].size()>n/2){now=j;break;}
        if(now==-1){printf("%lld\n",ans);continue;}
        else{
            sort(V[now].begin(),V[now].end());
            for(int i=V[now].size()-1;i>=n/2;i--) ans+=V[now][i];
            printf("%lld\n",ans);
        }
    }
    return 0;
}
