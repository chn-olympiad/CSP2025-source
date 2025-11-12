#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,i;
}b[100005],c[100005];
int t,n,a[100005][5],dp[105][105][105],ans,f1,y,cnt1,cnt2,f;
bool cmp(node a,node b){
    return a.a>b.a;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        ans=0;
        f=0;
        for(int i=1;i<=n;i++){
            if(a[i][2]){
                f=1;
            }
            if(a[i][3]){
                f1=1;
            }
        }
        if(f&&!f1){
            cnt1=0;
            cnt2=0;
            for(int i=1;i<=n;i++){
                if(a[i][1]<a[i][2]){
                    cnt2++;
                    c[cnt2].a=a[i][2];
                    c[cnt2].i=i;
                }else if(a[i][1]>a[i][2]){
                    cnt1++;
                    b[cnt1].a=a[i][1];
                    b[cnt1].i=i;
                }
            }
            if(cnt1<cnt2){
                for(int i=1;i<=n;i++){
                    if(a[i][1]==a[i][2]){
                        cnt1++;
                        b[cnt1].a=a[i][1];
                    }
                }
                sort(b+1,b+1+cnt1,cmp);
                sort(c+1,c+1+cnt2,cmp);
                for(int i=1;i<=cnt1;i++){
                    ans+=b[i].a;
                }
                for(int i=1;i<=n/2;i++){
                    ans+=c[i].a;
                }
                for(int i=n/2+1;i<=cnt2;i++){
                    ans+=a[c[i].i][1];
                }
            }else{
                for(int i=1;i<=n;i++){
                    if(a[i][1]==a[i][2]){
                        cnt2++;
                        c[cnt2].a=a[i][2];
                    }
                }
                sort(b+1,b+1+cnt1,cmp);
                sort(c+1,c+1+cnt2,cmp);
                for(int i=1;i<=cnt2;i++){
                    ans+=c[i].a;
                }
                for(int i=1;i<=n/2;i++){
                    ans+=b[i].a;
                }
                for(int i=n/2+1;i<=cnt1;i++){
                    ans+=a[b[i].i][2];
                }
            }
            cout<<ans<<"\n";
            continue;
        }else if(!f1){
            for(int i=1;i<=n;i++){
                b[i].a=a[i][1];
            }
            sort(b+1,b+1+n,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=b[i].a;
            }
            cout<<ans<<"\n";
            continue;
        }
        if(n<=200){
            ans=0;
            memset(dp,0,sizeof(dp));
            dp[1][0][0]=a[1][1];
            dp[0][1][0]=a[1][2];
            dp[0][0][1]=a[1][3];
            for(int i=2;i<=n;i+=2){
                for(int j=0;j<=i/2;j++){
                    for(int x=0;x<=i/2;x++){
                        y=i-x-j;
                        if(j>=2){
                            dp[j][x][y]=max(dp[j-2][x][y]+a[i][1]+a[i-1][1],dp[j][x][y]);
                        }
                        if(x>=2){
                            dp[j][x][y]=max(dp[j][x-2][y]+a[i][2]+a[i-1][2],dp[j][x][y]);
                        }
                        if(y>=2){
                            dp[j][x][y]=max(dp[j][x][y-2]+a[i][3]+a[i-1][3],dp[j][x][y]);
                        }
                        if(j&&x){
                            dp[j][x][y]=max(dp[j-1][x-1][y]+a[i][1]+a[i-1][2],dp[j][x][y]);
                            dp[j][x][y]=max(dp[j-1][x-1][y]+a[i][2]+a[i-1][1],dp[j][x][y]);
                        }
                        if(x&&y){
                            dp[j][x][y]=max(dp[j][x-1][y-1]+a[i][2]+a[i-1][3],dp[j][x][y]);
                            dp[j][x][y]=max(dp[j][x-1][y-1]+a[i][3]+a[i-1][2],dp[j][x][y]);
                        }
                        if(y&&j){
                            dp[j][x][y]=max(dp[j-1][x][y-1]+a[i][3]+a[i-1][1],dp[j][x][y]);
                            dp[j][x][y]=max(dp[j-1][x][y-1]+a[i][1]+a[i-1][3],dp[j][x][y]);
                        }
                        if(i==n){
                            ans=max(ans,dp[j][x][y]);
                        }
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
