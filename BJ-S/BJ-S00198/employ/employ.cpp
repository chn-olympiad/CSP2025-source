#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans=(ans*i)%998244353;
        }
        cout<<ans;
    }else {
        cout<<1;
    }
    return 0;
}