#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int now=1;
int ans;
int flag=0;
int a[5005];
int b[5005];
int c[5005];
void dfs(int now,int x){
    int c2[5005];
    memset(c2,0,sizeof(c2));
    if(now>n) return;
    if(x>now){
        int sum=0;
        for(int i=1;i<=now;i++){
            sum+=b[i];
        }
        if(sum>b[now]*2) ans++;
        return;
    }
    for(int i=x;i<=n;i++){
        b[x]=a[i];
        c2[b[x]]++;
        if(b[x]<=b[x-1]) continue;
        if(c2[b[x]]>c[b[x]]) continue;
        dfs(now,x+1);
        b[x]=0;
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }

    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]++;
        if(a[i]>1) flag=1;
    }
    sort(a+1,a+n+1);

    if(n==3){
        if(a[1]+a[2]+a[3]>a[3]*2){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    for(int i=3;i<=n;i++){
        dfs(i,1);
    }
    cout<<ans;
    return 0;
}
