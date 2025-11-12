#include <bits/stdc++.h>
using namespace std;

int n;
struct p{
    int a[4];
    int b[4];
};
p a[100010];

bool cmp(p p11,p p22){
    return p11.a[p11.b[1]]-p11.a[p11.b[2]]>p22.a[p22.b[1]]-p22.a[p22.b[2]];
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i<=n; ++i){
            scanf("%d%d%d",&a[i].a[1],&a[i].a[2],&a[i].a[3]);
            if(a[i].a[1]>=a[i].a[2] && a[i].a[1]>=a[i].a[3]){
                a[i].b[1] = 1;
                if(a[i].a[2] >= a[i].a[3]) a[i].b[2] = 2, a[i].b[3] = 3;
                else a[i].b[2] = 3, a[i].b[3] = 2;
            }
            else if(a[i].a[2]>=a[i].a[1] && a[i].a[2]>=a[i].a[3]){
                a[i].b[1] = 2;
                if(a[i].a[1] >= a[i].a[3]) a[i].b[2] = 1, a[i].b[3] = 3;
                else a[i].b[2] = 3, a[i].b[3] = 1;
            }
            else{
                a[i].b[1] = 3;
                if(a[i].a[1] >= a[i].a[2]) a[i].b[2] = 1, a[i].b[3] = 2;
                else a[i].b[2] = 2, a[i].b[3] = 1;
            }
        }
        sort(a+1,a+1+n,cmp);
        int ans = 0;
        int i = 1;
        int cnt[4] = {0,0,0,0};
        for(i = 1; i<=n; ++i){
            if(a[i].a[a[i].b[1]]==a[i].a[a[i].b[2]]) ans += a[i].a[a[i].b[1]];
            else if(cnt[a[i].b[1]]+1>n/2) ans += a[i].a[a[i].b[2]];
            else {
                ans += a[i].a[a[i].b[1]];
                ++cnt[a[i].b[1]];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
