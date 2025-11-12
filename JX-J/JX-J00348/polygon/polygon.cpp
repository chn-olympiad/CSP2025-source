#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,k;
int a[5010];

void dfs(int now,int sum,int xb,int mmax){
    if(now==k){
        if(mmax*2<sum){
            ans++;
            ans%=998244353;
            //printf("xb=%d\n",xb);
            //printf("sum=%d\n",sum);
            //printf("mmax=%d\n\n",mmax);

        }

        return ;
    }
    else {
        for(int i=xb+1;i<=k-now+xb&&i<=n;i++){
            mmax=max(mmax,a[i]);
            dfs(now+1,sum+a[i],i,mmax);
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(k=3;k<=n;k++){
        dfs(0,0,0,-9999);
    }
    cout<<ans;
    return 0;
}
