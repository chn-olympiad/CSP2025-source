#include<bits/stdc++.h>
using namespace std;
int n,ans=0,a[11451];
void dfs(int x,int maxs,int bds,int c,int f){
    /*cout<<a[bds]<<endl;*/
    if(bds>n)  return;
    if((x>(maxs*2))&&c>=3){
        ans+=f;
        if(ans>=998244353)  ans%=998244353;
        //for(int i=1;i<=c;i++)  cout<<b[i]<<' ';
        //cout<<' '<<x<<' '<<f<<endl;
        return;
    }
    for(int i=bds+1;i<=n;i++){
        f/=2;
        dfs(x+a[i],max(maxs,a[i]),i,c+1,f);
    }
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1,cmp);
    int f=pow(2,n-1);
    for(int i=1;i<=n-2;i++){
        dfs(a[i],a[i],i,1,f);
        f/=2;
    }cout<<ans;
    return 0;
}

