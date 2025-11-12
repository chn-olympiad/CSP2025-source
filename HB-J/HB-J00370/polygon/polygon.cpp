#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int P=998244353;
int n,a[N],c[N],s[N],ans=0;
bool b[N];
void dfs(int i,int x,int sum,int mx){
    if(i==n+1){
        if(x>=3){
            if(sum>mx*2){
                ans++;
                ans%=P;
            }
        }
        return;
    }
    s[i]=0;
    dfs(i+1,x,sum,mx);
    s[i]=1;
    dfs(i+1,x+1,sum+a[i],max(mx,a[i]));
}
int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(mx==1){
        long long x=1,y=1,ans=1;
        for(int i=1;i<=n;i++){
            ans*=2%P;
        }
        for(int i=2;i<=n;i++){
            x*=i%P;
        }
        for(int i=2;i<=n-2;i++){
            y*=i%P;
        }
        cout<<ans-1-n-x/(2*y);
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans;

    return 0;
}
