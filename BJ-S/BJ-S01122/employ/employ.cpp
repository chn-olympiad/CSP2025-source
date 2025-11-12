#include<cstdio>
#include<algorithm>
using namespace std;
const int N=505;
const long long MOD=998244353;
int n,m,c[N],a[N];
long long ans;
char s[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d%s",&n,&m,s+1);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    if(n<=10){
        for(int i=1;i<=n;i++)a[i]=i;
        do{
            int fail=0;
            for(int i=1;i<=n;i++){
                if(s[i]=='0')fail++;
                else if(c[a[i]]<=fail)fail++;
            }
            if(n-fail>=m)ans++;
        }while(next_permutation(a+1,a+n+1));
    }
    else{
        ans=1;
        for(int i=1;i<=n;i++)ans=ans*i%MOD;
    }
    printf("%lld\n",ans);
    return 0;
}

/*
Stanford REA RP++!希望12月有好事发生
*/