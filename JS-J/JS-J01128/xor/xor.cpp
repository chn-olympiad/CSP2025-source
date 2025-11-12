#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[200005],num[200005],vis[200005],sum=0;
void dfs(int t){
    if(t>=n)return;
    for(int i=1;i<=n-t;i++){
        int flag=0,s;
        for(int j=i;j<=i+t;j++){
            if(vis[j]!=0){
                flag=1;
                break;
            }
        }
        if(flag!=1&&num[i+t]^num[i-1]==k){
            sum++;
            for(int j=i;j<=i+t;j++){
                vis[j]=sum;
            }
        }
    }

    return;
}

int main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    cin>>n>>k;
    int x=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)x=0;
        num[i]=num[i-1]^a[i];
    }
    if(x&&k==0){
        cout<<n/2;
        return 0;
    }
    for(int i=0;i<n;i++)dfs(i);
    cout<<sum;
    return 0;
}
