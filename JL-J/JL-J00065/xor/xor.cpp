#include<bits/stdc++.h>
using namespace std;
int x,y,n,k,a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            x++;
        }
        if(a[i]==0){
            y++;
        }
    }
    if(x+y==n){
        if(k==1){
            cout<<x;
        }
        else{
            cout<<y+x/2;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            ans++;
        }
    }
    cout<<max(ans,1);
    return 0;
}
