#include<bits/stdc++.h>
using namespace std;

int t,n,f[35][35][35][35];
struct nd{int a,b,c;} a[100005];

bool cmp1(nd a,nd b){
    return a.a>b.a;
}

bool cmp2(nd a,nd b){
    return a.a-a.b>b.a-b.b;
}

bool cmp3(nd a,nd b){
    return a.a*2-a.b-a.c>b.a*2-b.b-b.c;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n; int sum1=0,sum2=0;
        for(int i=1;i<=n;i++) cin >> a[i].a >> a[i].b >> a[i].c, sum1+=a[i].b, sum2+=a[i].c;
        if(sum1==0&&sum2==0){
            int ans=0;
            sort(a+1,a+1+n,cmp1);
            for(int i=1;i*2<=n;i++) ans+=a[i].a;
            cout << ans << '\n';
            continue;
        }
        if(sum2==0){
            int ans=0;
            sort(a+1,a+1+n,cmp2);
            for(int i=1;i*2<=n;i++) ans+=a[i].a;
            for(int i=n/2+1;i<=n;i++) ans+=a[i].b;
            cout << ans << '\n';
            continue;
        }
        if(n==2){
            int ans=max({a[1].a+a[2].b,a[1].a+a[2].c,a[1].b+a[2].a,a[1].b+a[2].c,a[1].c+a[2].a,a[1].c+a[2].b});
            cout << ans << '\n';
            continue;
        }
        if(n<35){
            for(int i=1;i<=n;i++)
                for(int j=0;j*2<=n;j++)
                    for(int k=0;k*2<=n;k++)
                        for(int l=0;l*2<=n;l++){
                            int t=0;
                            if(j) t=max(t,f[i-1][j-1][k][l]+a[i].a);
                            if(k) t=max(t,f[i-1][j][k-1][l]+a[i].b);
                            if(l) t=max(t,f[i-1][j][k][l-1]+a[i].c);
                            f[i][j][k][l]=t;
                        }
            int ans=0;
            for(int i=0;i*2<=n;i++)
                for(int j=0;j*2<=n;j++)
                    for(int k=0;k*2<=n;k++) ans=max(ans,f[n][i][j][k]);
            cout << ans << '\n';
            continue;
        }
        else{
            int ans=0;
            for(int i=1;i<=n;i++) ans+=max({a[i].a,a[i].b,a[i].c});
            cout << ans << '\n';
        }
    }
    return 0;
}
