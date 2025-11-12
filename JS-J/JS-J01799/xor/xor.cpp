#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[500002];
int memo[500002];

int f(int idx){
    if(idx==n){
        if(a[idx]==k){
            return 1;
        }
        return 0;
    }
    if(memo[idx]!=-1){
        return memo[idx];
    }
    int sum=a[idx];
    if(sum==k){
        return 1+f(idx+1);
    }
    int ans=0;
    for(int i=idx+1;i<=n;i++){
        sum=(sum^a[i]);
        if(sum==k){
            ans= max(f(idx+1),f(i+1)+1);
            break;
        }
    }
    ans=max(ans,f(idx+1));
    memo[idx]=ans;
    return ans;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        memo[i]=-1;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<f(1);
    return 0;
}
