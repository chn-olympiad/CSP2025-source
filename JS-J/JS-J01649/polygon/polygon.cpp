#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,l;
    cin>>n;
    int a[3];
    if(n==3){
        for(int i=0;i<3;i++){
            cin>>a[i];
        }
    }
    else{
        cout<<0;
        return 0;
    }
    sort(a,a+3);
    if(a[2]<a[1]+a[0]){
        l=1;
    }
    else{
        l=0;
    }
    cout<<l;
    return 0;
}
