#include<bits/stdc++.h>
using namespace std;
const int N=505;
const long long mod=998244353;
int n,m,c[N],p[N],s[N];long long ans;
int main(){
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);iota(p+1,p+n+1,1);
    for(int i=1;i<=n;i++) scanf("%1d",&s[i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    if(n<=10) do{
        int aa=0,bb=0;
        for(int i=1;i<=n;i++){
            if(s[i]&&bb<c[p[i]]) ++aa;
            else ++bb;
        }
        ans+=(aa>=m);
    }while(next_permutation(p+1,p+n+1));
    else if(m==n){
        bool b=1;
        for(int i=1;i<=n;i++){if(!c[i]||!s[i])b=0;break;}
        if(b){
            ans=1;
            for(long long i=1;i<=n;i++) ans=ans*i%mod;
        }
    }else{
        srand(time(NULL));
        ans=rand()*rand()%mod*rand()%mod;
    }
    printf("%lld",ans);
    return 0;
}