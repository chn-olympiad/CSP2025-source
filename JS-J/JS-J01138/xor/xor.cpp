#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500050],ans,dp[1005][1005],cnt1[25],cnt2[25],cnt3[25];
bool A=1,B=1,f[1005];
long long  xo(long long a1,long long a2){
    long long now1=0,now2=0,xoans=0;
    if(a1==0){
        now1=1;
        cnt1[1]=0;
    }
    if(a2==0){
        now2=1;
        cnt2[1]=0;
    }
    while(a1>0){
        cnt1[++now1]=a1%2;
        a1/=2;
    }
    while(a2>0){
        cnt2[++now2]=a2%2;
        a2/=2;
    }
    int rear=1;
    int now3=1;
    for(int i=1;i<=now1;++i){
        if(i==now1){
            if(now2<now1){
                if(cnt1[now1]==1) cnt3[now3]=1;
                else cnt3[now3]=0;
            }
            if(cnt1[now1]==cnt2[now1])cnt3[now1]=0;
            else cnt3[now1]=1;
            for(int j=now1+1;j<=now2;++j){
                if(cnt2[j]==0)cnt3[j]=0;
                else cnt3[j]=1;
            }
            break;
        }else if(rear==now2){
            if(now1<now2){
                if(cnt2[now2]==1) cnt3[now3]=1;
                else cnt3[now3]=0;
            }
            if(cnt1[now2]==cnt2[now2])cnt3[now2]=0;
            else cnt3[now2]=1;
            for(int j=now2+1;j<=now1;++j){
                if(cnt1[j]==0)cnt3[j]=0;
                else cnt3[j]=1;
            }
            break;
        }
        if(cnt1[i]==cnt2[rear]) cnt3[now3++]=0;
        else cnt3[now3++]=1;
        ++rear;
    }
    int u=max(now1,now2);
    for(int i=u;i>=1;--i){
        if(cnt3[i]==1)xoans+=pow(2,i-1);
    }
    return xoans;
}
void vis(int l,int r){
    for(int i=l;i<=r;++i){
        f[i]=1;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>n>>k;
    cnt1[0]=-1;
    cnt2[0]=-1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]!=1) A=0;
        if(a[i]!=1&&a[i]!=0) B=0;
    }
    if(A){
        if(k==1) cout<<n;
        else if(k==0) cout<<n/2;
        else cout<<0;
    }else if(B){
        if(k==0){
            for(int i=1;i<=n;++i){
                if(a[i]==0) ++ans;
                if(a[i]==1&&a[i+1]==1){
                    ++ans;
                    ++i;
                }
            }
            cout<<ans;
        }else if(k==1){
            for(int i=1;i<=n;++i){
                if(a[i]==1) ++ans;
            }
            cout<<ans;
        }else{
            cout<<0;
        }
    }else{
        for(int i=1;i<=n;++i){
            int now=a[i];
            dp[i][i]=a[i];
            for(int j=i+1;j<=n;++j){
                dp[i][j]=xo(now,a[j]);
                dp[j][i]=dp[i][j];
                now=dp[i][j];
            }
        }
        for(int j=1;j<=n;++j){
            for(int i=j;i>0;--i){
               if(f[i]==1) break;
               if(dp[j][i]==k){
                 ++ans;
                 vis(i,j);
               }
            }
        }
        cout<<ans;
    }
    return 0;
}
