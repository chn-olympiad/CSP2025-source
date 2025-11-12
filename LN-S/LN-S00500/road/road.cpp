#include<bits/stdc++.h>
using namespace std;
int t,n,r,e[4],a[6],h=0;
int main(){
    freopen("road.in","r",std.in);
    freopen("road.out","w",std.out);
    cin>>t>>n>>r;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>e[i];
        }
        e.sort(0,e-1);
        h+=e[0];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>a[i];
        }
        a.sort(0,a-1);
        h+=a[0];
    }
    cout<<a;
    return 0;
}
