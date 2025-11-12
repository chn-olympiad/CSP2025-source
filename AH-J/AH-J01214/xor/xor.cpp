#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],maxn;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(n<=2)cout<<1;
    else if(maxn==0){
        cout<<(1+n)*n/2;
    }
    else if(maxn==1){

    }
    return 0;
}
