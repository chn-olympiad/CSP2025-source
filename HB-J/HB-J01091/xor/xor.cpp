#include<bits/stdc++.h>
using namespace std;
int a[1001],k,n,ans,dp[1001][1001],c[1001],maxn;
/*void dfs(int len,int data,int s){
    if(data==k){
        ans++;
        for(int i=s;i<=len;i++)
            b[i]=1;
        return;
    }
    if(len==n+1)
        return;
    dfs(len+1,data^a[len+1],s);
    for(int i=len+1;i<=n;i++){
        dfs(i,a[i],i);
    }
}*/
void dfs(int e){
    if(e==n+1){
        if(maxn<ans)
            maxn=ans;
        return;
    }

    for(int i=e+1;i<=n;i++){
        if(c[i]!=0){
            ans++;
            dfs(c[i]);
            ans--;
        }
    }
    dfs(n+1);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)
            f=1;
    }
    if(k==0&&f==0){
        cout<<n/2;
        return 0;
    }
    /*for(int i=1;i<=n;i++){
        dfs(i,a[i]);
    }*/
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(j==i){
                dp[i][j]=a[i];
            }
            else
                dp[i][j]=dp[i][j-1]^a[j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(dp[i][j]==k){
                c[i]=j;
                break;
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    dfs(0);
    cout<<maxn;
}
