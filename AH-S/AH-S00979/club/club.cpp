#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
int t,n,mx;
struct node{
    int j1,j2,j3;
}a[N];
struct node2{
    int d,c;
}dp[N][3];
void dfs(int step,int l1,int l2,int l3,int sum){
    if(step==n+1){
        mx=max(mx,sum);
        return;
    }
    if(l1<n/2){
        dfs(step+1,l1+1,l2,l3,sum+a[step].j1);
    }
    if(l2<n/2){
        dfs(step+1,l1,l2+1,l3,sum+a[step].j2);
    }
    if(l3<n/2){
        dfs(step+1,l1,l2,l3+1,sum+a[step].j3);
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    const char endl = '\n';
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        mx=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].j1>>a[i].j2>>a[i].j3;
        }
        dfs(1,0,0,0,0);
        cout<<mx<<endl;
    }
    return 0;
}
