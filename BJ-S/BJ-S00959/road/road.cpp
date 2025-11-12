#include<bits/stdc++.h>
using namespace std;
int a[10000000],b[100000000],c[100000000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    for(int i=0;i>m;i++){
        cin>>a[i]>>b[i]>>c[i];
        ans+=c[i];
    }
    cout<<ans;
    return 0;
}
