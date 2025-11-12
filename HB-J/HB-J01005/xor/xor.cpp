#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k,a[N],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int fa=1,fb=1,fc=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) fa=0;
        if(a[i]>1) fb=0;
        if(a[i]>255) fc=0;
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0) ans++;
            else if(a[i]==a[i+1]) ans++,i++;
        }
        cout<<ans;
        return 0;
    }else if(fa){
        cout<<n/2;
        return 0;
    }else if(fb){
        for(int i=1;i<=n;i++) if(a[i]==1) ans++;
        cout<<ans;
        return 0;
    }
    return 0;
}
