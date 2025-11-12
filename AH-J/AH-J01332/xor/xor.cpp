#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int i,n,k;
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>a[i];
    if(k==0)
        cout<<a[i];
    return 0;
}
