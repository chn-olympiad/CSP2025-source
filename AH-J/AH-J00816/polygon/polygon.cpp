#include<bits/stdc++.h>
using namespace std;
//#Shang4Shan3Ruo6Shui4
int n;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]>a[3])cout<<1;
        else cout<<0;
        return 0;
    }
    /*
    for(int i=1;i<=n-3;++i){
        for(int j=i+1;j<=n-2;++j){
            for(int z=j+1;z<=n;++z){

            }
        }
    }*/

    return 0;
}
