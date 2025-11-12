#include <bits/stdc++.h>
using namespace std;

struct man{
    int a1,a2,a3;
}a[100007];

int acnt,bcnt,ccnt;

long long t,n,ans;

bool acmp(man x,man y){
    if(x.a1!=y.a1)return x.a1>y.a1;
    return 1;
}

void dfs(int cnt,int now){
    if(acnt>n/2||bcnt>n/2||bcnt>n/2){
        return;
    }else if(now>n){
        if(cnt>ans)ans=cnt;
        return;
    }
    acnt++;
    dfs(cnt+a[now].a1,now+1);
    acnt--;
    bcnt++;
    dfs(cnt+a[now].a2,now+1);
    bcnt--;
    ccnt++;
    dfs(cnt+a[now].a3,now+1);
    ccnt--;
    return;
}

int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;

    while(t--){

        cin>>n;
        ans=0;
        for(int i=1;i<=n;++i){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }

        //A
        if(n>200)
        {
        bool aflag=0;
        for(int i=1;i<=n;i+=10){
            if(a[i].a2!=0||a[i].a3!=0){
                aflag=1;break;
            }
        }
        if(!aflag){
            sort(a+1,a+n+1,acmp);
            for(int i=1;i<=(n/2);++i){
                ans+=a[i].a1;
            }
            cout<<ans<<endl;
            continue;
        }
        }

        //B

        //n
        if(n<=31){
            ans=0;
            dfs(0,1);
            cout<<ans<<endl;
        }

    }

    return 0;
}
