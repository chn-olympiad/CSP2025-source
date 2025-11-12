#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int nums[1000100];
    int n,k;
    int cnt=0;
    bool vis[1000100];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        vis[i]=false;
        if(nums[i]==k){
            vis[i]=true;
            ++cnt;
        }
        else if(nums[i]^nums[i-1]==k&&(!vis[i])){
            vis[i]=true;
            vis[i-1]=true;
            ++cnt;
        }
    }
    if(n>900){
        cout<<cnt;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        for(int j=i;j>-1;j--){
            if(vis[j]) break;
            int h=0;
            for(int a=j;a<i+1;a++){
                h=h^nums[a];
            }
            if(h==k) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
