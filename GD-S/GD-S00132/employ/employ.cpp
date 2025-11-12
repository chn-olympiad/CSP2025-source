#include<bits/stdc++.h>
#define int long long
#define FILE(str) freopen(str".in","r",stdin),freopen(str".out","w",stdout)
inline void read(int &x){
    x=0;int f(1);
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    x=x*f;
}
#define pb push_back
using vi=std::vector <int>;
using pii=std::pair <int,int>;
using str=std::string;
const int MAXN=505,mod=998244353;
int n,m;
char s[MAXN];
int c[MAXN],p[MAXN];
signed main(){
    FILE("employ");
    read(n),read(m);
    scanf("%s",s+1);
    int f(1);
    for(int i=1;i<=n;i++) if(s[i]=='1') ++f;
    if(f<m){
        puts("0");
        return 0;
    }
    // if(f){
    //     int ans(1);
    //     for(int i=1;i<=n;i++) ans=ans*i%mod;
    //     printf("%lld\n",ans);
    //     return 0;
    // }
    for(int i=1;i<=n;i++) read(c[i]);
    std::sort(c+1,c+n+1);
    for(int i=1;i<=n;i++) p[i]=i;
    int ans(0);
    do{
        int cnt(0);
        for(int i=1;i<=n;i++){
            if(s[i]=='0'||cnt>=c[p[i]]) ++cnt;
        }
        if(m<=n-cnt) ++ans;
    }while(std::next_permutation(p+1,p+n+1));
    printf("%lld\n",ans);
}