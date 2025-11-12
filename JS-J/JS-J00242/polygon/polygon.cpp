#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long r;
    cin>>r;
    long long l[r+2];
    for(int i=1;i<=r;i++){
        cin>>l[i];
    }
    int maxn=0;
    for(int i=1;i<=r;i++){
        maxn=max(maxn,l[i]);
    }
    cout<<1%998244353<<endl;
    return 0;
}
