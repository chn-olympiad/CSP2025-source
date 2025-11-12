#include <bits/stdc++.h>

using namespace std;
long long n,k,a[10000],b,c,d;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[3]+a[3]>2*a[3]){
            c++;
        }
        cout<<c;
    }
    else if(n==4){
        if(a[1]+a[2]+a[3]>2*a[3]){
            c++;
        }
        else if(a[1]+a[2]+a[4]>2*a[4]){
            c++;
        }
        else if(a[1]+a[3]+a[4]>2*a[4]){
            c++;
        }
        else if(a[3]+a[2]+a[4]>2*a[4]){
            c++;
        }
        else if(a[1]+a[2]+a[4]+a[4]>2*a[4]){
            c++;
        }
        cout<<c+1;
    }



    return 0;
}
