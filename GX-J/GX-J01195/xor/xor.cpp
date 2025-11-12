#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    int a[1000];
    int p=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int l = a[i];
        int r = a[i]+k;
        if(l+k==r){
            p++;
        }
    }
    cout<<p;
    return 0;
}
