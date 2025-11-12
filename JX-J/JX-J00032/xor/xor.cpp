#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],j=0,m=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            m++;
        }
    }
    if(m==n){
        cout<<n/2;
    }else{
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    j++;
                    continue;
                }
                if(a[i]==a[i+1]){
                    j++;
                    i++;
                }
            }
            cout<<j;
        }
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    j++;
                    continue;
                }
                if(a[i]!=a[i+1]){
                    j++;
                    i++;
                }
            }
            cout<<j;
        }
    }
    return 0;
}
