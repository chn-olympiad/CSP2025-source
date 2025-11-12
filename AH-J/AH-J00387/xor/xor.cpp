#include<bits/stdc++.h>
using namespace std;
long long k,a[500005];
bool sel[500005];
int n,ans;
inline int check(int l,int r){
    long long tot=a[l];
    if(sel[l]) return -1;
    for(int k=l+1;k<=r;k++){
        if(sel[k]){
            tot=-1;
            break;
        }
        tot=tot^a[k];
    }
    return tot;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int len=1;len<=n;len++){
        for(int l=1;l<=n;l++){
            int r=l+len-1;
            if(r>n) break;
            if(check(l,r)==k){
                ans++;
                for(int i=l;i<=r;i++){
                    sel[i]=true;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
