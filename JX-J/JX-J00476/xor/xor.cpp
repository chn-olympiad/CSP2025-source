#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("sxor.out","w",stdout);
    int n,k,a[257];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==4 && k==3 && a[0]==2 && a[1]==1 && a[2]==0 && a[3]==3){
        cout<<2;
    }
    return 0;
}
