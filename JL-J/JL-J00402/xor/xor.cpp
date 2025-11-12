#include <bits/stdc++.h>
using namespace std;

int n,k,a[200050],s;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
        cout<<n/2;
    }
    else if(k<=1){
        int o0=0,o1=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0) o0++;
            if(a[i]==1) o1++;
        }
        if(k==1){
            int s1=min(o0,o1);
            if(min(o0,o1)==o0){
                s1+=o1-o0;
            }
            cout<<s1;
        }
        else{
            if(o0>=o1) cout<<o0/2+o1/2;
            else cout<<o1;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
              if(a[i]^a[j]==k){
                    s++;
                }
            }
        }
    }
    return 0;
}
