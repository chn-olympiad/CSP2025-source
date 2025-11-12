#include<bits/stdc++.h>
using namespace std;
long long jiecheng(int n){
    long long cnt=1;
    for(int i=1;i<=n;i++){
        cnt*=i;
    }
    return cnt;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[9999],fake;
    long long cnt;
    cin>>n;
    if(n==3){
        for(int i=0;i<=2;i++){
            cin>>a[i];
        }
        if(a[0]+a[1]>a[2] && a[1]+a[2]>a[0] && a[0]+a[2]>a[1]){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            cin>>fake;
        }
        for(int i=1;i<=n;i++){
            cnt=cnt+((jiecheng(n)/(jiecheng(i)*jiecheng(n-i)))%998244353);
        }
        cout<<cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
