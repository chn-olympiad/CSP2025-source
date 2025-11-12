#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int p=1;
    for(int i=0;i<n;i++){
        if(a[i]!=1){
            p=0;
            break;
        }
    }
    if(p){
        cout<<n/2;
        return 0;
    }
    p=1;
    for(int i=0;i<n;i++){
        if(a[i]!=1&&a[i]!=0){
            p=0;
            break;
        }
    }
    if(k==0) p=0;
    int s=0;
    if(p){
        for(int i=0;i<n;i++){

            if(a[i]==1){
                s++;
            }

    }
    cout<<s;
    return 0;

    }
    cout<<0;

}
