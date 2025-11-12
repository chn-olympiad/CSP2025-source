#include<bits/stdc++.h>
using namespace std;
int a[500050];
int n,k;
int x0,x1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) x0++;
        if(a[i]==1) x1++;
    }
    if(x0%2==1 && x1%2==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
