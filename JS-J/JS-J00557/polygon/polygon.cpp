#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[4],maxx=0,z=0;
    cin>>n;
    if(n==3){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            z+=a[i];
            maxx=max(maxx,a[i]);
        }
        if(maxx*2<z){
            cout<<'1';
        }else{
            cout<<'0';
        }
    }else{
        int aaa=1;
        for(int i=1;i<=n;i++){
            cin>>aaa;
        }
        int s=1,x=1;
        for(int i=3;i<=n;i++){
            for(int j=0;j<i;j++){
                s*=(n-j);
            }
            for(int j=1;j<=i;j++){
                x*=j;
            }
            z+=s/x;
            s=1;x=1;
        }
        cout<<z;
    }

    return 0;
}
