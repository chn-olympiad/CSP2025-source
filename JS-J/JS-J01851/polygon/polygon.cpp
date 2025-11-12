#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3){
        if(n<3){
            cout<<0;
            return 0;
        }
        int a[4];
        for(int i=1;i<=3;i++){
            cin>>a[i];
        }sort(a+1,a+n+1);
        if(a[1]+a[2]>a[3]){
            cout<<1<<endl;
            return 0;
        }else{
            cout<<0<<endl;
            return 0;
        }
    }else{
        cout<<n;
        return  0;
    }
}
