#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==3){
        int z=0,d;
        for(int i=0;i<n;i++){
            z=z+a[i];
        }
        d=max(max(a[0],a[1]),a[2]);
        if(z>2*d){
            cout<<"1";
        }else{
            cout<<"0";
        }
        return 0;
    }
    cout<<"0";
    return 0;
}
