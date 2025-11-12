#include<bits/stdc++.h>
using namespace std;

int n,a[5000],b[5000],ans;

void dfs(int i,long long sum,int maxn,int f){
    if(sum>maxn*2 && f==1){
        ans+=1;
        ans%=998244353;
    }
    if(i==n) return ;
    dfs(i+1,sum,maxn,0);
    dfs(i+1,sum+a[i+1],max(maxn,a[i+1]),1);
    return ;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(i,(long long)a[i],a[i],1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
