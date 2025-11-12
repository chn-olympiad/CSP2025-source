#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+5;
struct Rode {
    LL a1,a2,a3;
    LL max1,max2,max3;
    LL id;
}a[N];
LL cnt[5],n,maxn;
bool operator <(const Rode &x,const Rode &y){
    if(x.max1!=y.max1) return x.max1>y.max1;
    if(x.max2!=y.max2) return x.max2>y.max2;
    if(x.max3!=y.max3) return x.max3>y.max3;
    return x.id<y.id;
}
LL chan(LL maxn,LL x,LL y,LL z){
    if(maxn==x) return 1;
    if(maxn==y) return 2;
    return 3;
}
void dfs(LL cur,LL sum){
    if(cur>n){
        maxn=max(maxn,sum);
        return ;
    }
    if(cnt[a[cur].a1]+1<=n/2){
        cnt[a[cur].a1]++;
        dfs(cur+1,sum+a[cur].max1);
        cnt[a[cur].a1]--;
    }
    if(cnt[a[cur].a2]+1<=n/2){
        cnt[a[cur].a2]++;
        dfs(cur+1,sum+a[cur].max2);
        cnt[a[cur].a2]--;
    }
    if(cnt[a[cur].a3]+1<=n/2){
        cnt[a[cur].a3]++;
        dfs(cur+1,sum+a[cur].max3);
        cnt[a[cur].a3]--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    LL T,x,y,z;
    cin>>T;
    while(T--){
        memset(cnt,0,sizeof cnt);
        memset(a,0,sizeof a);
        bool fa=true;
        cin>>n;
        for(LL i=1;i<=n;i++){
            cin>>x>>y>>z;
            if(z!=0||y!=0)fa=false;
            a[i].id=i;
            a[i].max1=max(x,max(y,z));
            a[i].a1=chan(a[i].max1,x,y,z);
            a[i].max3=min(x,min(y,z));
            a[i].a3=chan(a[i].max3,x,y,z);
            if(x!=a[i].max1&&x!=a[i].max3){
                a[i].max2=x;
                a[i].a2=1;
            }
            if(y!=a[i].max1&&y!=a[i].max3){
                a[i].max2=y;
                a[i].a2=2;
            }
            if(z!=a[i].max1&&z!=a[i].max3){
                a[i].max2=z;
                a[i].a2=3;
            }
        }
        sort(a+1,a+n+1);
        if(fa){
            LL ans=0;
            for(LL i=1;i<=n/2;i++){
                ans+=a[i].max1;
            }
            cout<<ans<<endl;
            continue;
        }
        if(n<=16){
            maxn=0;
            dfs(1,0);
            cout<<maxn<<endl;
        }
        else{
            LL sum=0;
            for(LL i=1;i<=n;i++){
                if(cnt[a[i].a1]+1<=n/2){
                    cnt[a[i].a1]++;
                    sum+=a[i].max1;
                }
                else{
                    if(cnt[a[i].a2]+1<=n/2){
                        cnt[a[i].a2]++;
                        sum+=a[i].max2;
                    }
                    else{
                        cnt[a[i].a3]++;
                        sum+=a[i].max3;
                    }
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
