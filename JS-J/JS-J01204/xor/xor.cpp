#include<bits/stdc++.h>
#define ll long long
ll a[1000000];
int yihuo(int x,int y){
    ll sum=0;
    ll xx=1;
    while(x>0||y>0){
        if(x%2!=y%2){
            sum+=xx;
            xx*=2;
            x/=2;
            y/=2;
        }

    }
    return sum;
}
int sum(int l,int r){
    if(l=r){
        return 0;
    }
    int x=a[l];
    for(int i=l+1;i<=r;i++){
        x=yihuo(a[i],x);
    }
    return x;
}
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,k;
    int s=0;
    cin>>n>>k;
    bool f=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f=0;
        }
    }
    if(f){
        cout<<n;
        return 0;
    }
    for(int i=0;i<n;){
        for(int j=i;j<n;j++){
           if(sum(i,j)==0){
               s++;
               i=j+1;
               break;
           }
        }
    }
    cout<<s;
    return 0;
}

