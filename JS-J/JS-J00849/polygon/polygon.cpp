#include<bits/stdc++.h>
#define int  long long
using namespace std;
int n;
int a[5010];
int cntsum=0;
int xa,fn;
void dfs(int step,int s,int cnt,int l){
    if(step==cnt){
        if(s>xa){
           // cout<<s<<" ";
            cntsum++;
        }
        return;
    }
    for(int i=l+1;i<=fn+1-(cnt-step);i++){
        dfs(step+1,s+a[i],cnt,i);
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        xa=a[i];
        fn=i-1;
        for(int j=2;j<=i-1;j++){
            dfs(0,0,j,0);
            cntsum%=998244353;
        }
    }
    cout<<cntsum;
    return 0;
}
