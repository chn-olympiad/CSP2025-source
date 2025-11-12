#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500000+9];
long long ans;
int dfs(int step,int num){
    if(step>n){
        return n+1;
    }
    num=num^a[step];
    if(num==k){
        ans++;
        return step;
    }
    dfs(step+1,num);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;){
        if(a[i]^0==k){
            ans++;
            i++;
        }
        else{
            i=dfs(i,0);
        }
    }
    cout<<ans;
    return 0;
}
