#include<bits/stdc++.h>
using namespace std;
int a[500005];
int x[1005][1005];
int vis[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int flag=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=1)flag=0;
    }
    if(flag==1&&k==0){
        int ans=n/2;
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        x[i][i]=a[i];
        for(int j=i+1;j<=n;j++){
            x[i][j]=x[i][j-1]^a[j];
        }
    }
    int sum=0;
    flag=1;
    for(int i=1;i<=n;i++){
        if(a[i]>1)flag=0;
    }
    if(k==0&&flag==1){
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                sum++;
                vis[i]=1;
            }

        }
        for(int i=1;i<n;i++){
            if(vis[i]==0&&x[i][i+1]==0){
                sum++;
                vis[i+1]=1;
            }
        }
        cout<<sum;
        return 0;
    }
    if(k==1&&flag==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)sum++;
        }
        cout<<sum;
        return 0;
    }

}
