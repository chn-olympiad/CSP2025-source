#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int maxl=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        maxl=max(maxl,a);
    }
    cout<<maxl;
    return 0;
}
