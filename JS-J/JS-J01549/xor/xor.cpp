#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],K[25];
bool f[25];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
    if(n<=1000){
        int l=1;
        for(int i=1;i<=n;++i){
            int s=0;
            for(int j=i;j>=l;--j){
                s^=a[j];
                if(s==k){
                    ans++;
                    l=i+1;
                    break;
                }
            }
        }
        printf("%lld",ans);
        return 0;
    }
    for(int i=0;i<=20;++i) K[i]=((k>>i)&1ll);
    for(int i=1;i<=n;++i){
        bool flag=true;
        for(int j=0;j<=20;++j){
            int x=((a[i]>>j)&1ll);
            if((!f[j])&&(x!=K[j])) flag=false;
        }
        if(flag){
            ans++;
            for(int j=0;j<=20;++j) f[j]=false;
        }else{
            for(int j=0;j<=20;++j){
                if(((a[i]>>j)&1ll)==1){
                    f[j]=true;
                }
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
