#include <bits/stdc++.h>
using namespace std;

int n,a[5500];

int maxx(int a[],int n){
    int maxn=0;
    for(int i=1;i<=n;i++){
        if(a[i]>maxn)
            maxn=a[i];
    }
    return maxn;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        int maxa=max(a[1],max(a[2],a[3]));
        int he=a[1]+a[2]+a[3];
        if(he>2*maxa){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else if(maxx(a,n)==1){
        int s;
        for(int i=3;i<=n;i++){
            s+=n-i+1;
        }
        cout<<s;
    }
    return 0;
}
