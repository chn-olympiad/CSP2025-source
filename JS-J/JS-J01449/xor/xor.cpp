#include<bits/stdc++.h>
using namespace std;
int a[500006],b[500006],vis[500006];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        a[i]^=a[i-1];
    }
    if(k==1){
        int ans=0;
        for(int i=1;i<=n;i++){
            if(b[i]==k) ans++;
        }
        cout<<ans;
        return 0;
    }
    else if(k==0){
        int ans=0;
        for(int i=1;i<=n;i++){
            if(b[i]==k) ans++;
            if(b[i]==1){
                int tmp=1;
                while(b[i+1]==1){
                    i++;
                    tmp++;
                }
                ans+=tmp/2;
            }
        }
        cout<<ans;
        return 0;
    }
    else{
        int ans=0;
        for(int i=1;i<=n;i++){
            if(b[i]==k){
                // cout<<i<<endl;
                ans++;
                vis[i]=1;
            }
        }
        int l=1,rr=n,r=2;
        while(vis[rr])rr--;
        while(vis[l]) l++;
        while(r<=rr){
            for(;!vis[r]&&!vis[l]&&r<=rr;r++){
                if((a[r]^a[l-1])==k){
                    for(int j=l;j<=r;j++) vis[j]=1;
                    // cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r-1];
                    // cout<<"\n";
                    ans++;
                    l=r+1;r=l+1;
                }
            }
            l++;
            r=l+1;
            while(vis[l]||vis[r]){
                if(vis[l]){
                    l++,r++;
                }
                else{
                    l=r+1,r=l+1;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}