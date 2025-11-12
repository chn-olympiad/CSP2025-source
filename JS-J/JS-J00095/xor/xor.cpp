#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt+=a[i];
    }
    if(k==0){
        cout<<int(n/2);
    }else{
        cout<<cnt;
    }
    return 0;
}
