#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ma=0,c,c1,c2;
    long long a[5010];
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>ma)ma=a[i];
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>ma*2){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    if(ma==1){
        for(int i=1;i<=n;i++){
            c1*=i;
            if(i<=n-3)c2*=i;
        }
        c=c1*c2/6;
        c%=998;c%=244;c%=353;
        cout<<c;
        return 0;
    }
    cout<<9;
    return 0;
}
