#include<bits/stdc++.h>

using namespace std;
int a[100010],b[100010],c[100010];
int n;
int dfs(int d,int e,int f,int x,int ans){
    if(x==n){
        return ans;
    }
    if(d==n/2){
        return max(dfs(d,e+1,f,x+1,ans+b[x]),dfs(d,e,f+1,x+1,ans+c[x]));
    }
    if(e==n/2){
        return max(dfs(d+1,e,f,x+1,ans+a[x]),dfs(d,e,f+1,x+1,ans+c[x]));
    }
    if(f==n/2){
        return max(dfs(d,e+1,f,x+1,ans+b[x]),dfs(d+1,e,f,x+1,ans+a[x]));

    }
    return max(dfs(d,e+1,f,x+1,ans+b[x]),max(dfs(d+1,e,f,x+1,ans+a[x]),dfs(d,e,f+1,x+1,ans+c[x])));

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int u=0;u<t;u++){
    int ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        ans=dfs(0,0,0,0,0);
        cout<<ans<<endl;
    }


    return 0;
}
