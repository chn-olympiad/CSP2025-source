#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
int n;
int a[N],ans=0;
int A(int n,int i){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    return ans;
}
int C(int n,int i){
    return A(n,i)/A(i,i);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        ans+=C(n,i);
    }
    cout<<ans;
    return 0;
}
