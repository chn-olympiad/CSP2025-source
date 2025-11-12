#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n,k;
    cin>>n>>k;
    int a[n];
    int a1=0,a0=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1)a1++;
        if(a[i]==0)a0++;
    }

    if(k==0){
        cout<<a1/2+a0/2;
    }

    else if(k==1){
        cout<<a1;
    }
    return 0;
}
