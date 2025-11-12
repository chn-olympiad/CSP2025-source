#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n];
    int ans=0;
    bool b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[n]=false;
    }
    for(int l=0;l<n;l++){
        int cnt=0;
        int lc=l;
        for(int r=l;r<n;r++){
            cnt=a[r]^cnt;
            if(cnt==k){
                bool iok=true;
                for(int i=lc;i<=r;i++){
                    if(b[i]==true){
                        iok=false;
                        break;
                    }
                }
                if(iok){
                    for(int i=lc;i<=r;i++){
                        b[i]=true;
                    }
                    lc=r;
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
