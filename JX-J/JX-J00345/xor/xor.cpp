#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e6+10;
int n,k,s[N],ans;
bool vis[M];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        s[i]=s[i-1]^x;
    }
    vis[0]=1;
    int l=1;
    for(int r=1;r<=n;r++){
        if(vis[k^s[r]^s[l-1]]){
            ans++;
            for(int i=l;i<r;i++)
                if((s[i]^s[l-1])!=0) vis[s[i]^s[l-1]]=0;
            l=r+1;
            continue;
        }
        vis[s[r]^s[l-1]]=1;
    }
    cout<<ans;
    return 0;
}