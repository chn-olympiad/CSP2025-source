#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int q,w,e;
}a[100010];

bool cmp(node a1,node a2){
    if(a1.q==a2.q){
        if(a1.w==a2.w){
            return a1.e>a2.e;
        }
        return a1.w>a2.w;
    }
    return a1.q>a2.q;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t,n,dp[100010][5],maxa=-1;
    cin>>t;
    while(t--){
        maxa=-1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].q>>a[i].w>>a[i].e;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=2;i<=n/2;i++){//swap
            int q1=0,w1=0,e1=0;
            q1=a[i].q;
            w1=a[i].w;
            e1=a[i].e;
            a[i].q=a[i+1].q;
            a[i].w=a[i+1].w;
            a[i].e=a[i+1].e;
            a[i+1].q=q1;
            a[i+1].w=w1;
            a[i+1].e=e1;
        }
        dp[1][1]=a[1].q;
        dp[1][2]=a[1].w;
        dp[1][3]=a[1].e;
        for(int i=2;i<=n;i++){
            dp[i][1]=max(a[i].q+dp[i-1][2],a[i].q+dp[i-1][3]);
            dp[i][2]=max(a[i].w+dp[i-1][1],a[i].w+dp[i-1][3]);
            dp[i][3]=max(a[i].e+dp[i-1][1],a[i].e+dp[i-1][2]);
            maxa=max(max(dp[i][1],dp[i][2]),dp[i][3]);
        }

        cout<<maxa<<endl;
    }
    return 0;
}
//ccfhaishirenma
