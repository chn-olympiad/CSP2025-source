#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;

ll t,n;
ll divf[N];
ll ans;

struct node{
    ll a,b,c;
}p[N];

void dfs(ll cnt,ll a,ll b,ll c){

    if(cnt==n+1){

        ll res=0;
        for(int i=1;i<=n;i++){
            if(divf[i]==1){
                res += p[i].a;
            }
            if(divf[i]==2){
                res += p[i].b;
            }
            if(divf[i]==3){
                res += p[i].c;
            }
        }
        ans = max(res,ans);
        return;
    }

    if(a<n/2){
        divf[cnt]=1;
        dfs(cnt+1,a+1,b,c);
        divf[cnt]=0;
    }
    if(b<n/2){
        divf[cnt]=2;
        dfs(cnt+1,a,b+1,c);
        divf[cnt]=0;
    }
    if(c<n/2){
        divf[cnt]=3;
        dfs(cnt+1,a,b,c+1);
        divf[cnt]=0;
    }

}

inline bool cmp(node x,node y){
    return x.a > y.a;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);

    cin >> t;

    while(t--){
        cin >> n;

        ll ddd=0;

        for(int i=1;i<=n;i++){
            cin >> p[i].a >> p[i].b >> p[i].c;
            if(p[i].b==0 && p[i].c==0) ddd++;
        }

        if(ddd==n){
            sort(p+1,p+1+n,cmp);
            ans=0;
            for(int i=1;i<=n/2;i++){
                ans += p[i].a;
            }
            cout << ans<<endl;
            continue;
        }

        ans = 0;
        dfs(1,0,0,0);
        cout << ans<<endl;

    }

    return 0;
}

/*
18
4
13
*/
