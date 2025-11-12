#include <bits/stdc++.h>
using namespace std;
namespace Light_Tea{
    void Main();
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    Light_Tea::Main();
    return 0;
}
namespace Light_Tea{
    using i64 = long long;

    constexpr int kN=500+5, MOD=998244353;

    int n,m,c[kN];
    char S[kN];

    int Fac(int n){
        int res=1;
        for(int i=2; i<=n; i++) res=1LL*res*i%MOD;
        return res;
    }

    namespace Sub1{
        int p[kN];
        void Main(){
            int ans=0;
            for(int i=1; i<=n; i++) p[i]=i;
            do{
                int cnt=0;
                for(int i=1; i<=n; i++){
                    int u=p[i];
                    if(cnt<c[u]&&S[i]=='1') continue;
                    else cnt++;
                }
                if(n-cnt>=m) ans++;
            }while(next_permutation(p+1,p+n+1));
            printf("%d\n",ans);
        }
    }

    namespace Sub2{
        int buf[kN];
        void Main(){
            int ans=Fac(n);
            
            for(int i=1; i<=n; i++) buf[c[i]]++;
            for(int i=1; i<=n; i++) buf[i]+=buf[i-1];

            int cnt=0, res=1;
            for(int i=1; i<=n; i++) if(S[i]=='1'){
                res=1LL*res*(buf[i-1]-cnt)%MOD, cnt++;
            }
            res=1LL*res*Fac(n-cnt)%MOD;

            printf("%d\n",(ans-res+MOD)%MOD);
        }
    }

    void Main(){
        scanf("%d%d%s",&n,&m,S+1);
        for(int i=1; i<=n; i++) scanf("%d",&c[i]);
        sort(c+1,c+n+1);

        int cnt=0;
        for(int i=1; i<=n; i++) if(S[i]=='1') cnt++;
        if(cnt<m){
            puts("0"); return ;
        }

        if(m==n){
            if(c[1]>0&&cnt==n) printf("%d\n",Fac(n));
            else puts("0");
            return ;
        }

        if(n<=10){
            Sub1::Main();
            return ;
        }

        if(m==1){
            Sub2::Main();
            return ;
        }
    }
}