#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,s=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        s+=i;
    }
    cout<<s-n/4;
    return 0;
}
