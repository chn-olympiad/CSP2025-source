#include<bits/stdc++.h>
using namespace std;
int n,k,a[555555],m=1,an;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int i,j,k;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
        cout<<n/2;
        return 0;
    }
    for(i=1;i<=n;i++){
        if(a[i]^a[i+1]!=k){
            if(a[i]==1){
                an++;
            }
        }else{
            an++;
            i++;
        }
    }
    cout<<an;
    return 0;
}
