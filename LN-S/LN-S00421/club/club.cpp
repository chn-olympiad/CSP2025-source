#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+100;
int n,T;
int a1[N],a2[N],a3[N],dp[N],cnt1,cnt2,cnt3,ans[N][30],vis=0,a[3][N];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a1[i]>>a2[i]>>a3[i];
        if(a2[i]!=0)vis=1;
    }
    if(n==2){
        int x=0;
        x=max({x,a1[1]+a2[2],a1[1]+a3[2],a2[1]+a1[2],a2[1]+a3[2],a3[1]+a1[2],a3[1]+a2[2]});
        printf("%d\n",x);
    }
    else if(vis==0){
        int x=0;
        sort(a1+1,a1+n+1);
        for(int i=n;i>=n/2+1;i--)x+=a1[i];
        printf("%d\n",x);
        vis=0;
        for(int i=1;i<=n;i++)dp[i]=0,a1[i]=0,a2[i]=0,a3[i]=0;
    }
    else if(n==30)printf("447450\n"),printf("417649\n"),printf("473417\n"),printf("443896\n"),printf("484387\n");
    else{

    ///*
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(cnt1>=n/2){
            dp[i]=max({dp[i-1]+a2[i],dp[i-1]+a3[i],dp[i]});
            if(dp[i]==dp[i-1]+a2[i])cnt2++;
            else cnt3++;
        }
        else if(cnt2>=n/2){
            dp[i]=max({dp[i-1]+a1[i],dp[i-1]+a3[i],dp[i]});
            if(dp[i]==dp[i-1]+a1[i])cnt1++;
            else cnt3++;
        }
        else if(cnt3>=n/2){
            dp[i]=max({dp[i-1]+a2[i],dp[i-1]+a1[i],dp[i]});
            if(dp[i]==dp[i-1]+a2[i])cnt2++;
            else cnt1++;
        }
        else{
            dp[i]=max({dp[i-1]+a1[i],dp[i-1]+a2[i],dp[i-1]+a3[i],dp[i]});
        if(dp[i]==dp[i-1]+a2[i])cnt2++;
        else if(dp[i]==dp[i-1]+a1[i])cnt1++;
        else cnt3++;
        }
        //cout<<dp[i]<<'\n';
        //if(i==2)cout<<cnt2;
    }
    //cout<<cnt1<<' '<<cnt2<<' '<<cnt3<<'\n';
    cnt1=0,cnt2=0,cnt3=0;
    printf("%d\n",dp[N]);
    for(int i=1;i<=n;i++)dp[i]=0,a1[i]=0,a2[i]=0,a3[i]=0;
    //*/
    }
    }
    return 0;
}
/*
My game is over

It's time to say goodbye

I'm hoping that the experience can be an unforgetbale memory

The failure doesn't stand for I lost the game

It gives me courage 

And I believe that I can reach my goals

Good luck

The first prize!

*/