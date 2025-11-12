#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    if (n<3){
        cout<<0;
    }
    if (n==3){
        if(a[0]+a[1]+a[2]>max(max(a[0],a[1]),a[2])*2){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    if (n==4){
        int cnt=0;
        if (a[0]+a[1]+a[2]+a[3]>max(max(max(a[0],a[1]),a[2]),a[3])*2){
            cnt++;
        }
        if(a[0]+a[1]+a[2]>max(max(a[0],a[1]),a[2])*2){
            cnt++;
        }
        if(a[0]+a[1]+a[3]>max(max(a[0],a[1]),a[3])*2){
            cnt++;
        }
        if(a[0]+a[2]+a[3]>max(max(a[0],a[2]),a[3])*2){
            cnt++;
        }
    }
    return 0;
}
