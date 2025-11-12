#include <bits/stdc++.h>
using namespace std;
bool can(int a[],int n){
    int num=0,great=-1;
    for(int i=0;i<n;i++){
        num+=a[i];
        if(a[i]>great) great = a[i];
    }
    if(num >2*great) return true;
    return false;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[10005],he=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int b[3]={a[i],a[j],a[k]};
                if(can(b,3)) he++;

            }
        }
    }
    cout<<he;

    return 0;
}
