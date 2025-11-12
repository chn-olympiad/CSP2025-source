#include<bits/stdc++.h>
using namespace std;
int n,a[5555],b[5555];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int i,j;
    int an=0;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    for(i=1;i<=n;i++){
        for(j=i+2;j<=n;j++){
            if(j-i>=2&&b[j]-b[i-1]>a[j]*2){
                an++;
            }
        }
    }
    cout<<an;
    return 0;
}
