#include <bits/stdc++.h>
using namespace std;
int n,k,a[500001],maxn=0;
int xo(int x,int y){
    int s[22]={0},m[22]={0},d[22]={0},n=0,l=0,sum=0;
    if(x<y)swap(x,y);
    if(x==0)n=1;
    if(y==0)l=1;
    while(x!=0){
        s[++n]=x%2;
        x/=2;
    }
    while(y!=0){
        m[++l]=y%2;
        y/=2;
    }
    for(int i=1;i<=l;i++)if(s[i]!=m[i])d[i]=1;
    for(int i=l+1;i<=n;i++)if(s[i])d[i]=1;
    for(int i=n;i>=1;i--){
        sum*=2;
        if(d[i])sum++;
    }
    return sum;
}
void dfs(int x,int y){
    int s=0;
    bool p=1;
    for(int i=x;i<=n+1;i++){
        if(i==n+1){
            maxn=max(maxn,y);
            return;
        }
        s=xo(s,a[i]);
        if(s==k){
            p=0;
            dfs(i+1,y+1);
            break;
        }
    }
    if(p)dfs(x+1,y);
    return;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)dfs(i,0);
    cout<<maxn;
    return 0;
}
