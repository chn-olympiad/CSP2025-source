#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long ans=1;
    long long a;
    cin>>a;
    for(int i=1;i<n*m;i++){
        long long b;
        cin>>b;
        if(b>a)
            ans++;
    }
    if(ans%n==0){
        a=ans/n;
        cout<<a<<' ';
    }
    else{
        a=ans/n+1;
        cout<<a<<' ';
    }
    if(a%2==1)
        cout<<ans-(a-1)*n;
    else
        cout<<a*n-ans+1;
    return 0;
}

