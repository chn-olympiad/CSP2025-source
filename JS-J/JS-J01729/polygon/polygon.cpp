#include<bits/stdc++.h>
using namespace std;
const int INF=998244353;
#define int long long
int n;
int a[5005];
int ans;
int mem[5005];
void dfs(int al,int pos,int mx,int bs){
    if(bs>=3){
        if(al>mx*2){
            ans+=1;
            ans%=INF;
        }
    }
    if(pos==n)return ;
    for(int i=pos+1;i<=n;i++){
        if(a[i]>mx)mx=a[i];
        dfs(al+a[i],i,mx,bs+1);
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)f=0;
    }
    if(f==1){
        int c=1;
        for(int i=n-2;i<=n;i++){
            c*=i;
            c%=INF;
        }
        c/=6;
        ans+=c;
        ans%=INF;
        for(int i=4;i<=n;i++){
            c*=(n-i+1);
            c/=i;
            c%=INF;
            ans+=c;
            ans%=INF;
        }
        cout<<ans<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        dfs(a[i],i,a[i],1);
    }
    cout<<ans;
    return 0;
}
