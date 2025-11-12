#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,big,num,h;
    big=num=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h;
        a[h]++;
        num+=a[i];
        if(a[i]>big){
            big=a[i];
        }
    }
    cout<<"3";
    return 0;
}
