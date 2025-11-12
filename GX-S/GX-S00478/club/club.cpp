#include<bits/stdc++.h>
using namespace std;
int a[20000][20000],n,t,sum,dp[20000],d[3],tt;//the maximum agreement
void finfswap(int q,int l){
    int mx=0,mx0=0,mn=100000,mn0=0,t0;//mx0,mn0 are _
    for(int i=0;i<q;i++){
        if(i==0){
            mx=a[l][i]-a[a[4][i]][i];
            mn=a[l][i]-a[a[4][i]][i];
        }
        if(a[l][i]-a[a[4][i]][i]>=mx&&i!=q){
            mx=max(mx,a[l][i]-a[a[4][i]][i]);
            mx0=i;
        }
        if(a[l][i]-a[a[4][i]][i]<mn&&i!=q){
            mn=min(mn,a[l][i]-a[a[4][i]][i]);
            mn0=i;
//          cout<<'_'<<mn<<mn0<<'_';
        }
    }
//  cout<<'>'<<d[0]<<d[1]<<d[2]<<'<';
    a[a[l][mn0]][mn0]+=mn;
    dp[q]=dp[q]-mn;
    d[mn0]++;
    d[l]--;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int T=0;T<t;T++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[0][i]>>a[1][i]>>a[2][i];//storage their agreement
            a[3][i]=0;
            a[4][i]=0;
            a[5][i]=0;//prepare
            for(int j=0;j<3;j++){
                if(a[a[3][i]][i]<a[j][i]){
                    a[3][i]=j;//the biggest is a[3][i]
                }
                if(a[a[5][i]][i]>a[j][i]){
                    a[5][i]=j;//the smallest is a[5][i]
                }
            }
            for(int j=0;j<3;j++){
                if(j!=a[3][i] && j!=a[5][i]){
                    a[4][i]=j;
                }
            }
        }
//      cout<<endl;
        for(int i=0;i<n;i++){
            dp[i]=dp[i-1]+a[a[3][i]][i];
            d[a[3][i]]++;
//          cout<<dp[i]<<'*';
            for(int j=0;j<3;j++){
                if(d[j]>n/2){
                    finfswap(i,j);
//                  cout<<dp[i]<<"!*";
                }
            }
//          cout<<' ';
            if(i>=n-1){
                cout<<dp[n-1]<<endl;
            }
        }
        for(int i=0;i<n;i++){
            dp[i]=0;
            for(int j=0;j<6;j++){
                a[j][i]=0;
            }
        }
        for(int j=0;j<3;j++){
            d[j]=0;
        }
        n=0;
    }
    cout<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
