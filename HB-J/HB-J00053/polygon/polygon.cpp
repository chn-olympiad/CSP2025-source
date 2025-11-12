#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e3+5;
long long n,a[N];
long long f(long long n){
    int x=1;
    for(int i=2;i<=n;i++)x*=i;
    return x;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    if(n<=3){
        if(n<3){
            cout<<0;
        }else{
            int x=max(max(a[0],a[1]),a[2]);
            if(2*x<a[0]+a[1]+a[2])cout<<1;
            else cout<<0;
        }
    }else{
        cout<<f(n)/(f(n-3)*f(3));
    }
    return 0;
}
