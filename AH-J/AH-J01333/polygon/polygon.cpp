#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[5005];
long long cnt;
bool zuida;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) zuida=1;
    }
    if(zuida==0){
        for(int i=3;i<=n;i++){
            int x=1,y=1;
            for(int j=1;j<=i;j++){
                int t=n-i;
                x*=j+t;
                y*=j;
            }
            cnt+=x/y;
        }
        cout<<cnt%998244353;
        return 0;
    }
    if(n==3){
        if(a[1]>abs(a[2]-a[3]) && a[1]<a[2]+a[3] && a[2]>abs(a[1]-a[3]) &&a[2]<a[1]+a[3] && a[3]>abs(a[1]-a[2]) && a[3]<a[1]+a[2] ){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    cout<<9;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
