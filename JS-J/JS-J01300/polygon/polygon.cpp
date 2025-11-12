#include <bits/stdc++.h>

using namespace std;
int n;
long long ans;
int a[5000+9];
void dfs(int step,long long num,int z){
    if(a[step]>z){
        z=a[step];
    }
    num+=a[step];
    if(num>z*2){
        ans++;
    }
    for(int i=step+1;i<=n;i++){
        dfs(i,num,z);
    }
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(i,0,0);
    }
    cout<<ans%998244353;
    return 0;
}
