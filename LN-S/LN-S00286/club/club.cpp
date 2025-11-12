#include <bits/stdc++.h>
using namespace std;
int a[100005][4],c[100005],b[100005];
inline void solve(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    long long ans=0;
    int c1=0,c2=0,c3=0;
    for(int i=1;i<=n;i++){
        int mx=max({a[i][1],a[i][2],a[i][3]});
        ans+=mx;
        if(mx==a[i][1]){
            b[i]=1;
            c1++;
        } else if(mx==a[i][2]){
            b[i]=2;
            c2++;
        } else if(mx==a[i][3]){
            b[i]=3;
            c3++;
        }
    }
    if(c1>n/2){
        for(int i=1;i<=n;i++){
            if(b[i]==1)
                c[i]=a[i][1]-max(a[i][2],a[i][3]);
            else
                c[i]=1<<30;
        }
        sort(c+1,c+n+1);
        for(int i=c1-n/2;i>=1;i--){
            ans-=c[i];
        }
    } else if(c2>n/2){
        for(int i=1;i<=n;i++){
            if(b[i]==2)
                c[i]=a[i][2]-max(a[i][1],a[i][3]);
            else
                c[i]=1<<30;
        }
        sort(c+1,c+n+1);
        for(int i=c2-n/2;i>=1;i--){
            ans-=c[i];
        }
    } else if(c3>n/2){
        for(int i=1;i<=n;i++){
            if(b[i]==3)
                c[i]=a[i][3]-max(a[i][2],a[i][1]);
            else
                c[i]=1<<30;
        }
        sort(c+1,c+n+1);
        for(int i=c3-n/2;i>=1;i--){
            ans-=c[i];
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}
