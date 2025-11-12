#include<bits/stdc++.h>
using namespace std;
int m,a[100000],cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        if(a[i]+a[i+1]+a[i+2]>a[i]*2){
            cnt++;
        }
    }
    cout<<cnt;

     return 0;
}
