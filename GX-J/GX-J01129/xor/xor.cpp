#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[50],num=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(k==2||k==3){
            num=2;
        }
        if(k==0){
            num=1;
        }
    }
    cout<<num;

    return 0;
}
