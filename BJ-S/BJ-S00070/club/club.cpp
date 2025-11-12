#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int a,b,c,maxx,maxx2;
}a[N];
bool cmp1(node a,node b){
    if(a.maxx!=b.maxx)
        return a.maxx>b.maxx;
    else return a.maxx2>b.maxx2;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].maxx=max(max(a[i].a,a[i].b),a[i].c);
            if(a[i].a==a[i].maxx){
                a[i].maxx2=max(a[i].b,a[i].c);
            }
            if(a[i].b==a[i].maxx){
                a[i].maxx2=max(a[i].a,a[i].c);
            }
            if(a[i].c==a[i].maxx){
                a[i].maxx2=max(a[i].b,a[i].a);
            }
        }
        sort(a+1,a+1+n,cmp1);
        int cnta=0,cntb=0,cntc=0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(a[i].maxx==a[i].a&&cnta<n/2){
                ans+=a[i].maxx;
                a[i].a=a[i].maxx=0;
                cnta++;
            }
            else if(cnta==n/2){
                if(cntb<n/2&&a[i].b==a[i].maxx2){
                    cntb++;
                    a[i].b=a[i].maxx2=0;
                    ans+=a[i].maxx2;
                }
                else{
                    cntc++;
                    a[i].c=0;
                    ans+=a[i].c;
                }
            }
            else if(a[i].maxx==a[i].b&&cntb<n/2){
                ans+=a[i].maxx;
                a[i].b=a[i].maxx=0;
                cntb++;
            }
            else if(cntb==n/2){
                if(cnta<n/2&&a[i].a==a[i].maxx2){
                    cnta++;
                    a[i].a=a[i].maxx2=0;
                    ans+=a[i].maxx2;
                }
                else{
                    cntc++;
                    a[i].c=0;
                    ans+=a[i].c;
                }
            }
            else if(cntc<n/2){
                ans+=a[i].maxx;
                a[i].c=a[i].maxx=0;
                cntc++;
            }
            else if(cntc==n/2){
                if(cntb<n/2&&a[i].b==a[i].maxx2){
                    cntb++;
                    a[i].b=a[i].maxx2=0;
                    ans+=a[i].maxx2;
                }
                else{
                    cnta++;
                    a[i].a=0;
                    ans+=a[i].a;
                }
            }
            if(cnta+cntb+cntc==n) break;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int a,b,c;
}a[N];
int dp[4][N];
struct verb{
    int a, b, c;
}dp2[4][N];
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
        }
        long long maxx=0;
        dp[1][1]=a[1].a;
        dp2[1][1].a=1;
        dp[2][1]=a[1].b;
        dp2[2][1].b=1;
        dp[3][1]=a[1].c;
        dp2[3][1].c=1;
        for(int i=2;i<=n;i++){
            if(dp[1][i-1]!=0){
                dp[1][i]=max(dp[1][i],max(dp[2][i],dp[3][i]))+a[i-1].a;
                if(dp[1][i]>dp[2][i]&&dp[1][i]>dp[3][i]){
                    dp2[1][i].a=dp2[1][i-1].a+1;
                    dp2[1][i].b=dp2[1][i-1].b;
                    dp2[1][i].c=dp2[1][i-1].c;
                    if(dp2[1][i].a>n/2) dp[1][i]=0;
                }
                else if(dp[3][i]>dp[2][i]&&dp[3][i]>dp[1][i]){
                    dp2[1][i].a=dp2[1][i-1].a;
                    dp2[1][i].b=dp2[1][i-1].b;
                    dp2[1][i].c=dp2[1][i-1].c+1;
                    if(dp2[1][i].c>n/2) dp[1][i]=0;
                }
                else{
                    dp2[1][i].a=dp2[1][i-1].a;
                    dp2[1][i].b=dp2[1][i-1].b+1;
                    dp2[1][i].c=dp2[1][i-1].c;
                    if(dp2[1][i].b>n/2) dp[1][i]=0;
                }
            }
            if(dp[2][i-1]!=0){
                dp[2][i]=max(dp[2][i],max(dp[1][i],dp[3][i]))+a[i-1].b;
                //cout<<dp[2][i]<<'\n'<<max(dp[2][i-1],max(dp[1][i-1],dp[3][i-1]))<<'\n';
                if(dp[1][i-1]>dp[2][i-1]&&dp[1][i-1]>dp[3][i-1]){
                    dp2[2][i].a=dp2[2][i-1].a+1;
                    dp2[2][i].b=dp2[2][i-1].b;
                    dp2[2][i].c=dp2[2][i-1].c;
                    if(dp2[2][i].a>n/2) dp[2][i]=0;

                }
                else if(dp[3][i-1]>dp[2][i-1]&&dp[3][i-1]>dp[1][i-1]){
                    dp2[2][i].a=dp2[2][i-1].a;
                    dp2[2][i].b=dp2[2][i-1].b;
                    dp2[2][i].c=dp2[2][i-1].c+1;
                    if(dp2[2][i].c>n/2) dp[2][i]=0;

                }
                else{
                    dp2[2][i].a=dp2[2][i-1].a;
                    dp2[2][i].b=dp2[2][i-1].b+1;
                    dp2[2][i].c=dp2[2][i-1].c;
                    if(dp2[2][i].b>n/2) dp[2][i]=0;

                }
            }
            if(dp[3][i]!=0){
                dp[3][i]=max(dp[2][i],max(dp[1][i],dp[3][i]))+a[i-1].c;
                if(dp[1][i]>dp[2][i]&&dp[1][i]>dp[3][i]){
                    dp2[3][i].a=dp2[3][i-1].a+1;
                    dp2[3][i].b=dp2[3][i-1].b;
                    dp2[3][i].c=dp2[3][i-1].c;
                    if(dp2[3][i].a>n/2) dp[3][i]=0;

                }
                else if(dp[3][i]>dp[2][i]&&dp[3][i]>dp[1][i]){
                    dp2[3][i].a=dp2[3][i-1].a;
                    dp2[3][i].b=dp2[3][i-1].b;
                    dp2[3][i].c=dp2[3][i-1].c+1;
                    if(dp2[3][i].c>n/2) dp[3][i]=0;

                }
                else{
                    dp2[3][i].a=dp2[3][i-1].a;
                    dp2[3][i].b=dp2[3][i-1].b+1;
                    dp2[3][i].c=dp2[3][i-1].c;
                    if(dp2[3][i].b>n/2) dp[3][i]=0;

                }
            }
            long long maxx2=max(dp[1][i],max(dp[2][i],dp[3][i]));
            maxx=max(maxx2,maxx);
        }
        cout<<maxx<<'\n';
        for(int i=1;i<=3;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=0;
                dp2[i][j].a=0;
                dp2[i][j].b=0;
                dp2[i][j].c=0;
            }
        }
    }
    return 0;
}
*/
