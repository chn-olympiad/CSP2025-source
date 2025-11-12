#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int n,k,ans=0;
vector<vector<int>> s;
bool check(int l,int r){
    int ans=-1;
    if(l==r)
        ans=a[l];
    else{
        ans=a[l];
        for(int i=l+1;i<=r;i++)
            ans^=a[i];
    }
    return ans==k;
}
void dfs(int l,int depth){
    if(l>n){
        ans=max(depth,ans);
        return;
    }
    for(int i=0;i<s[l].size();i++)
        dfs(s[l][i]+1,depth+1);
    return;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    bool flagA=true,flagB=true;
    int flagBi1=0,flagBi0=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)
            flagA=false;
        if(a[i]!=0&&a[i]!=1)
            flagB=false;
        if(a[i]==1)
            flagBi0++;
        if(a[i]==1)
            flagBi1++;
    }
    if(k==0&&flagA){
        cout<<n/2<<"\n";
        return 0;
    }else if(k==1&&flagB){
        cout<<flagBi1<<"\n";
        return 0;
    }
    s.reserve(n+5);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(check(i,j))
                s[i].push_back(j);
    dfs(1,0);
    cout<<ans<<"\n";
    return 0;
}
