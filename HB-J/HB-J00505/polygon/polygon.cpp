#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long ans=0;
int n;
int a[5*100000+10];
int f1=1;

namespace n10{
    struct node{
        int tim;
        int sum;
        int maxn;
    };
    vector<node> res;
    void main(){
        res.push_back({0,0,0});
        for(int i=1;i<=n;i++)
            for(auto y:res) res.push_back({y.tim+1,y.sum+a[i],max(y.maxn,a[i])});
        for(auto y:res){
            if(y.tim>=3&&y.sum>y.maxn*2) ans++,ans%=MOD;
            //cout << y.sum << ' '<< y.maxn;
        }printf("%lld",ans%MOD);
    }

}
namespace a1{
    long long f[5000+10];
    long long C(int n1,int m1){
        return (f[n1]/f[m1-1]/f[m1])%MOD;
    }
    void main(){
        f[0]=f[1]=1;
        for(int i=2;i<=5000+1;i++) f[i]=(f[i-1]%MOD*i)%MOD;
        for(int i=3;i<=n;i++) ans=(ans+C(n,i))%MOD;
        printf("%lld",ans%MOD);
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),f1&=(a[i]==1);
    if(f1) a1::main();
    else if(n<=13) n10::main();
    else a1::main();
    return 0;
}
