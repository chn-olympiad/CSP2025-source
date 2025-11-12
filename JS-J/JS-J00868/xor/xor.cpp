#include <bits/stdc++.h>
using namespace std;
#define int long long
struct qiqi{
    int l,r;
};
vector<qiqi>g;
int n,k,a[500052],sum[500052],ans,maxx[500052];
bool vis[500052];
inline void f(int x,int num){
    if(num<maxx[x]){
        return ;
    }
    //cout<<x<<";";
    if(x==(int)g.size()){
        if(num>ans){
            ans=num;
        }
        return ;
    }
    bool ok=1;
    for(int i=g[x].l;i<=g[x].r;++i){
        if(vis[i]){
            ok=0;
            break;
        }
    }
    if(ok){
        for(int i=g[x].l;i<=g[x].r;++i){
            vis[i]=1;
        }
        f(x+1,num+1);
        for(int i=g[x].l;i<=g[x].r;++i){
            vis[i]=0;
        }
        maxx[x]=max(maxx[x],num);
    }
    f(x+1,num);
    return ;
}
signed main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
    //cout<<(0^1)<<"\n";
    //cout<<(1^3)<<" "<<(1^3^5^4^(5^4))<<"\n";
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n-i+1;++j){
            int temp=sum[j+i-1]^sum[j-1];
            if(temp==k){
                g.push_back({j,j+i-1});
                //cout<<j<<" "<<(j+i-1)<<"\n";
            }
        }
    }
    /*for(int i=1;i<=n;++i){
        cout<<i<<"\n";
        for(int j=i;j<=n;++j){
            int temp=sum[j]^sum[i-1];
            if(temp==k){
                cout<<i<<" "<<j<<"\n";
                g.push_back({i,j});
                break;
            }
            if(j==n){
                break;
            }
        }
        if(i==n){
            break;
        }
    }*/
    f(0,0);
    printf("%lld\n",ans);
    return 0;
}
