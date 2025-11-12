#include<bits/stdc++.h>
using namespace std;
const int INF=100000001;
struct t{
    int p1,p2,p3;
}a[1000001];
bool f[100001];
int sum=-INF;
void dfs(int n,int x,int sum1,int sum2,int sum3,int ans){
    if(x==n+1){
        if(sum1*2<=n&&sum2*2<=n&&sum3*2<=n){
            sum=max(ans,sum);

        }
        return;
    }
    if(sum1*2<n)dfs(n,x+1,sum1+1,sum2,sum3,ans+a[x].p1);
    if(sum2*2<n)dfs(n,x+1,sum1,sum2+1,sum3,ans+a[x].p2);
    if(sum3*2<n)dfs(n,x+1,sum1,sum2,sum3+1,ans+a[x].p3);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i].p1>>a[i].p2>>a[i].p3;
        dfs(n,0,0,0,0,0);
        cout<<sum<<endl;
        sum=-INF;
    }
    return 0;
}
