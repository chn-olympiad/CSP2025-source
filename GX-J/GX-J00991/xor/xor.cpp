#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,p=0;
    cin>>n>>k;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k=0){
        for(int i=0;i<n;i++){
            if(a[i]==1){
                if(a[i+1]==1){
                    p++;
                    i++;
                }
            }
            if(a[i]==0) p++;
        }
    }
    if(k=1){
        for(int i=0;i<n;i++){
            if(a[i]==1) p++;
        }
    }
    cout<<p;
    return 0;
}
