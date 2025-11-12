#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main( ){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum=0,com=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int p=1;p<=n;p++){
        for(int j=1;j<=n-p;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    int m;
    m=a[n];
    if(n<3||sum>2*a[n]){
        cout<<0;
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[j]+a[j+1]>a[j+2]){
                    com++;
                }
            }
        }
        cout<<com;
    }
    return 0;
}
