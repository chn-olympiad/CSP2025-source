#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w".stdout);
    int n,a[5023];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[j]<a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    if(sum>2*a[0])cout<<1;
    else cout<<0;
    return 0;
}
