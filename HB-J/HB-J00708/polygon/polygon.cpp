#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum>2*max(a[1],max(a[2],a[3])))cout<<1;
    else cout<<0;
    return 0;
}