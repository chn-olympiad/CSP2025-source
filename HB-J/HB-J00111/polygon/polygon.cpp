#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,c,z=0;
    cin>>n;
    int a[n];
    for(int i=0;i<=n-1;i++) cin>>a[i];
    for(int j=3;j<=n;j++){
    for(int i=0;i<=n-j;i++){
        for(int k=0;k<=j-1;k++){
             c=c+a[i+k];
             cout<<a[i+k]<<" ";
        }
        cout<<endl;
        if(c>=a[i+j]) z++;
    }
    }
    cout<<z;
    return 0;
}
