#include<bits/stdc++.h>
using namespace std;
int s,k,o,t;
int n;
int a[5001],b[5001];
int poly(int e){
    if(e>n){
        return 0;
    }
    for(int i=1;i<=e;i++){
        int z=i+1,r=1;
        for(int u=z;u<e;u++){
            for(int j=3;j<e;j++){
                r++;
                s+=b[z+r];
            }
            for(int w=1;w<=e;w++){
                if(s>b[z+r+w]){
                    k++;
                }
            }
            z++;
            s=b[i]+b[z]+b[z+r];
        }
    }
    return poly(e+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t+=a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    if(t==n){
        for(int i=1;i<=n;i++){
            s+=n-1;
            s/=2;
        }
        cout<<s;
        return 0;
    }
    for(int i=1;i<=n;i++){
        k=0;
        for(int j=1;j<=n;j++){
            if(a[j]>k){
                k=a[j];
            }
        }
        for(int j=1;j<=n;j++){
            if(a[j]==k){
                b[i]=a[j];
                a[j]=0;
                break;
            }
        }
    }
    if(n==3){
        if(b[3]+b[2]>b[1]){
            cout<<1;
            return 0;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    k=0;
    s=0;
    poly(3);
    cout<<k;
    return 0;
}
