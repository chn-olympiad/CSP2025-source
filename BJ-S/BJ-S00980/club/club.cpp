#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005],b[100005],c[100005],mx=0;
long long dfs(long long ans1,long long ans2,long long ans3,long long temp,long long ans){
    if(temp>=n+1||ans1>n/2||ans2>n/2||ans3>n/2){
        return 0;
    }
        if(ans1<n/2){
            dfs(ans1+1,ans2,ans3,temp+1,ans+a[temp]);
            mx=max(ans+a[temp],mx);
        }
        if(ans2<n/2){
            dfs(ans1,ans2+1,ans3,temp+1,ans+b[temp]);
            mx=max(ans+b[temp],mx);
        }
        if(ans3<n/2){
            dfs(ans1,ans2,ans3+1,temp+1,ans+c[temp]);
            mx=max(ans+c[temp],mx);
        }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int l=1;l<=t;l++){
        mx=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        dfs(0,0,0,1,0);
        cout<<mx<<endl;
    }
    return 0;
}
