#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m,sum=0,s0=0,m0=0;
    cin>>n>>m;
    int a[100005];
    bool f=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1) f=0;
        else sum++;
        if(a[i]==0) s0++;
        if(a[i]==m) m0++;
    }
    if(f==1){
        cout<<n/2;
        return 0;
    }
    if(m==1){
        cout<<sum;
        return 0;
    }
    else if(m==0){
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1]){
                s0++;
                i++;
            }
        }
        cout<<s0;
        return 0;
    }
    cout<<m0;
    return 0;
}
