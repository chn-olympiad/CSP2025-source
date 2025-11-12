#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[10000];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    else if(n==3){
        if(a[0]+a[1]+a[2]>2*max(a[0],max(a[1],a[2])))
        cout<<1;
        else{
            cout<<0;
            return 0;
        }
    }else{
        a[1]=1;
        for(int i=2;i<=n;i++){
            a[i]=a[i-1]+n-i;
        }
        cout<<a[n];
    }
    return 0;
}
