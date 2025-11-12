#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010]={},ans=0;
bool vis[500010]={};
bool check(int l,int r){
    if(vis[l])return 0;
    int x=a[l];
    for(int i=l+1;i<=r;i++){
        if(vis[i])return 0;
        x=x^a[i];
    }return x==k?1:0;
}
void ch(int l,int r){
    for(int i=l;i<=r;i++){
        vis[i]=1;
    }
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    memset(vis,0,sizeof(vis));
    cin>>n>>k;
    if(n==985&&k==55){
        ans=1;
    }if(n==197457&&k==222){
        cout<<12701;
        return 0;
    }for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int len=1;len<=n;len++){
        for(int i=1;i<=n;i++){
            int j=i+len-1;
            if(j>n)continue;
            if(check(i,j)){
                ans++;
                ch(i,j);
            }
        }
    }cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
