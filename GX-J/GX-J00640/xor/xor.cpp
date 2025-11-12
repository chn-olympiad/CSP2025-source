#include<bits/stdc++.h>
using namespace std;
int n,k,sum=0,a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){sum++;}
    }
    cout<<sum;
    return 0;
}
