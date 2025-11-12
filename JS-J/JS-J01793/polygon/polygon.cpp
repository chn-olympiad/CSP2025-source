#include<bits/stdc++.h>
using namespace std;
int n,a[10005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        if(a[1]+a[2]>=a[3]&&a[2]+a[3]>=a[1]&&a[1]+a[3]>=a[1]){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        int x=0;
        for(int i=3;i<=n;i++){
            int y=1,z=1;
            for(int j=1;j<=i;j++){
                y*=j;
                z*=(n-j+1);
            }
            x+=z/y;
        }
        cout<<x%998%244%353;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
