#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[100],ans=0,dt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=2) {
        cout<<0;
        dt=1;}
    if(n==3){
        if(a[0]+a[1]>a[2] && max(a[0],a[1]) - min(a[0],a[1]) < a[2]) ans++;
        if(a[2]+a[1]>a[0]&& max(a[2],a[1]) - min(a[2],a[1]) < a[0]) ans++;
        if(a[0]+a[2]>a[1]&& max(a[0],a[2]) - min(a[0],a[2]) < a[1]) ans++;
        }
    if(dt==0){
        cout<<ans;}
    return 0;
}
