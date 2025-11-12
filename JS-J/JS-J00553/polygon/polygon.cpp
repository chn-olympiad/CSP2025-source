#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int a[N];
int main(){
    freopen("polygon.in","r",stdin);
    frropen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(a[0]+a[1]>=a[2]*2){
        cout<<1;
        return 0;
    }
    else{
        cout<<0;
        return 0;
    }
    return 0;
}
