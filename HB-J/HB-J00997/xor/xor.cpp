#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a[100100]={0},b[100100]={0};
    int zd1=0,zd2=0;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]^a[i];
        if(i==1){
            b[i]=a[i];
        }
    }
    //for(int i=1;i<=n;i++){
        //cout<<a[i]<<" "<<b[i]<<endl;
    //}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            zd1^=a[j];
        }
        for(int j=i;j<=n;j++){
            zd2^=a[j];
        }
        if(zd2==k&&zd1==k){
            cout<<2;
            return 0;
        }
    }

    if((zd2==k&&zd1!=k)&&(zd1==k&&zd2!=k))cout<<1;
    return 0;
}
