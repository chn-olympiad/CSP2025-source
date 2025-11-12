#include <bits/stdc++.h>
using namespace std;
int n,k,a[1000005],b[1000005],_1,_0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i])_1++;
        else _0++;
        b[i]=a[i];
    }
    if(k==1){
        cout<<_1;
        return 0;
    }
    sort(b+1,b+n+1);
    if(b[1]==b[n]){
        cout<<_0;
    }
    else{
        for(int i=2;i<=n;i++){
            if(a[i-1]==a[i]){
                _0++;
                i++;
            }
        }
        cout<<_0;
    }
    return 0;
}
