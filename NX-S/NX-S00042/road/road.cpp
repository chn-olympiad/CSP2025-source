#include<bits/stdc++.h>
using namespace std;
struct city{
    int a1,a2,a3;
}a[1000000];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,s=0;
    cin>>n>>m>>k;
    int o[n+k];
    for(int i=0;i<n+k;i++){
        o[i]=0;
    }
    for(int i=0;i<m;i++){
        cin>>a[i].a1>>a[i].a2>>a[i].a3;
        s+=a[i].a3;
    }
    cout<<s;
    return 0;
}
