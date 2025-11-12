#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n,sum,ans;
int maxx=INT_MIN;
int a[5005];
int cnt=3;
void dfs(int i,int x,int sum,int last){
    if(x==cnt){
        if(sum>last*2){
            ans++;
            ans%=mod;
        }
        return ;
    }
    if(i==n){
        if(sum>last*2){
            ans++;
            ans%=mod;
        }
        return ;
    }
    dfs(i+1,x+1,sum+a[i],a[i]);
    dfs(i+1,x,sum,last);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        maxx=max(maxx,a[i]);
    }
    sort(a+1,a+1+n);
    if(n<3){
        cout<<0;
        return 0;
    }
    else if(n==3){
        if(sum<=maxx*2){
            cout<<0;
            return 0;
        }
        else if(sum>maxx*2){
            cout<<1;
            return 0;
        }
    }
    else {
        int temp=n-1;
        while(temp--){
            dfs(1,0,0,0);
            cnt++;
            if(cnt>=n){
                break;
            }
        }
        cout<<ans%mod;
    }
    return 0;
}
