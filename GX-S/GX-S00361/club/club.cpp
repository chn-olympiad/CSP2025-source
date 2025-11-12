#include <bits/stdc++.h>
#define MAXN 100010
#define HAJIMINANBEILVDOU 0
using namespace std;
int a[MAXN],b[MAXN],c[MAXN];
typedef struct ffff{
    int aa;
    int bb;
} ffff;
ffff ff[MAXN];
int dp[210][110][110];
int n;
bool cmp(int& a,int& b){
    return a>b;
}
bool ccca(ffff& a,ffff& b){
    return a.aa>b.aa;
}
bool cccb(ffff& a,ffff& b){
    return a.bb>b.bb;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int aaaa; cin>>aaaa;
    while(aaaa--){
        cin>>n;
        bool tsxz_a=true;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if((b[i]!=0)||(c[i]!=0)) tsxz_a=false;
        }
        if(tsxz_a==true){
            sort(a+1,a+1+n,cmp);
            int ans=0;
            for(int i=1;i<=(n/2);i++) ans+=a[i]; cout<<ans<<endl;
        }
        else if(n<=200){
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=n;i++){
                for(int j=0;j<=(n/2);j++){
                    for(int k=0;k<=(n/2);k++){
                        //what the duck?
                        int what=0,the=0,duck=0;
                        if(j>=1) what=dp[i-1][j-1][k]+a[i];
                        if(k>=1) the=dp[i-1][j][k-1]+b[i];
                        if(((i-j-k)>=1)&&(i-j-k)<=(n/2)) duck=dp[i-1][j][k]+c[i];
                        dp[i][j][k]=max(what,max(the,duck));
                    }
                }
            }
            int ans=0;
            for(int i=0;i<=(n/2);i++){
                for(int j=0;j<=(n/2);j++){
                    if((n-i-j)>(n/2)) continue;
                    if(dp[n][i][j]>ans) ans=dp[n][i][j];
                }
            }
            cout<<ans<<endl;
        }
        else{
            int ans1=0,ans2=0;
            for(int i=1;i<=n;i++){
                ff[i].aa=a[i];
                ff[i].bb=b[i];
            }
            sort(ff+1,ff+1+n,ccca);
            for(int i=1;i<=(n/2);i++){
                ans1+=ff[i].aa;
                ans1+=ff[n-i+1].bb;
            }
            for(int i=1;i<=n;i++){
                ff[i].aa=a[i];
                ff[i].bb=b[i];
            }
            sort(ff+1,ff+1+n,cccb);
            for(int i=1;i<=(n/2);i++){
                ans2+=ff[i].bb;
                ans2+=ff[n-i+1].aa;
            }
            cout<<max(ans1,ans2)<<endl;
        }
    }
    return HAJIMINANBEILVDOU;
}
