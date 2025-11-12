#include<bits/stdc++.h>
using namespace std;
int n,a[5001],q[5001],ser;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        q[i]=q[i-1]+a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(q[j]-q[i-1]>2*a[i] && j-i+1>=3){
                ser=(ser+1)%998244353;
                cout<<q[j]-q[i-1]<<" ";
            }
            for(int p=i+1;p<j;p++){
                for(int o=p;o<j;o++){
                    if(q[j]-q[i-1]-(q[o]-q[p-1])>2*a[i] && j-i+1-(p-o+1)>=3){
                        ser=(ser+1)%998244353;
                        cout<<q[j]-q[i-1]-(q[o]-q[p-1])<<" ";
                    }
                }
            }
        }
    }
    cout<<ser%998244353;
    return 0;
}
