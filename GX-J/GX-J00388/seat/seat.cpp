#include<bits/stdc++.h>
using namespace std;
int c,r,n,m,a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int num=a[1],num1;
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--)
        if(a[i]==num)num1=n*m+1-i;
    c=(num1-1)/m+1;
    if(c%2==0){
        if(num1%n==0){
            r=1;
            cout<<c<<" "<<r<<endl;
            return 0;
        }

        r=n+1-num1%n;

    }
    else{
        if(num1%n==0){
            r=n;
            cout<<c<<" "<<r<<endl;
            return 0;
        }

        r=num1%n;

    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
