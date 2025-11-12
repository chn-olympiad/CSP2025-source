#include<bits/stdc++.h>
using namespace std;
int main(){
    int y,z=0,a[1000],d;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>y;
    for(int i=1;i<=y;i++){
        cin>>a[i];
    }
    for(int i=1;i<=y-3;i++){
            if(max(a[i],a[i+1])>a[i+2]){
                d=max(a[i],a[i+1]);
            }
            else{
                d=a[i+2];
            }
        if(a[i]+a[i+1]+a[i+2]>2*d){
            z++;
        }
    }
    cout<<z;
    return 0;
}
