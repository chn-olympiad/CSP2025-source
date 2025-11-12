#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long mod=998244353,n,m,c[1000],num[50][1000],cnt[50],ls,nm,ans,d[2][20][262144],now;
char s[1000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    //cout<<1<<"\n";
    if(m==n){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
    }
    //cout<<1<<"\n";
    for(int i=1;i<(1<<(n));i++){
        ls=i;nm=0;
        while(ls){
           if(ls&1) nm++;
           ls=ls/2;
        }
        num[nm][++cnt[nm]]=i;
    }
    //out<<1<<"\n";
    d[0][0][0]=1;
    for(int i=1;i<=n;i++){
        now=now^1;
        for(int j=0;j<=i;j++){
            for(int k=1;k<=cnt[i];k++){
                for(int l=1;l<=n;l++){
                    //cout<<i<<j<<k<<l<<"\n";
                    if((1<<(l-1))&num[i][k]){
                        if(s[i]=='0'||c[l]==0||j-1>=c[l]){
                            if(j>1) d[now][j][num[i][k]]=(d[now][j][num[i][k]]+d[now^1][j-1][num[i][k]^(1<<(l-1))])%mod;
                        }
                        if(s[i]=='1'&&c[i]>0&&c[i]>=j){
                            d[now][j][num[i][k]]=(d[now][j][num[i][k]]+d[now^1][j][num[i][k]^(1<<(l-1))])%mod;
                        }
                   }
                }
            }
        }
    }
    //cout<<1<<"\n";
    for(int i=0;i<=n-m;i++){
        ans+=d[now][i][num[n][cnt[n]]];
    }
    cout<<ans;
    return 0;
}
