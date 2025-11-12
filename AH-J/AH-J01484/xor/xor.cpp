#include<bits/stdc++.h>
#define f for
using namespace std;
const int mn=5e5+5;
int n,k,a[500005],g[mn][mn];
void input(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}
// bool xor(bool x,bool y){
//     return a==!b 
// }
int qvan(int l,int r){
    int x=a[l];
    f(int i=l+1;i<=r;i++){
        x|=a[i];
    }
    return x;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    input();
    int z=-1,ans=0;
    f(int l=1;l<=n;l++){
        f(int r=l;r<=n;r++){
            g[l][r]=qvan(l,r);
            if(g[l][r]=k and l>z){
                ans++;
                z=r;
                l=r+1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}