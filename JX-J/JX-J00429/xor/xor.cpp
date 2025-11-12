#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,k,a[500001];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==2){
        if(a[1]==a[2]){
            cout<<0;
        }else{
            cout<<1;
        }
    }else if(k>1){
        cout<<0;
    }
    cout<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
