#include<bits/stdc++.h>
using namespace std;
int v[100001][3];
int dis[100001];
int summax;
void dp(int ka,int kb,int kc,int n,int sum){
    if(n==0&&summax<sum)summax=sum;
    for(int i=1;i<=n;i++){
        if(ka>0&&dis[i]==0){
            dis[i] = 1;
            dp(ka-1,kb,kc,n-1,sum+v[i][1]);
            dis[i] = 0;
        }
        if(kb>0&&dis[i]==0){
            dis[i] = 1;
            dp(ka,kb-1,kc,n-1,sum+v[i][2]);
            dis[i] = 0;
        }
        if(kc>0&&dis[i]==0){
            dis[i] = 1;
            dp(ka,kb,kc-1,n-1,sum+v[i][3]);
            dis[i] = 0;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int n,k;
    while(t--){
        summax = 0;
        cin>>n;
        k = n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>v[i][j];
            }
        }
        dp(k,k,k,n,0);
        cout<<summax<<endl;
    }

    return 0;
}
