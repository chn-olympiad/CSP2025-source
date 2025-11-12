#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int temp=1;
    for(int i=1;i<=n;i++){
        temp=max(temp,a[i]);
    }
    if(temp==1){
        cout<<1;
    }
    else{
        cout<<temp;
    }

    return 0;
}
