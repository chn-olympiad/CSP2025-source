#include<bits/stdc++.h>
using namespace std;
long long n,k;
int a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<a[k]-1;


    return 0;
}
