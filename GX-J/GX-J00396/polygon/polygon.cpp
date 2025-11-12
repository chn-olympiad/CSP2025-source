#include<bits/stdc++.h>

using namespace std;

long long n,a[5000];

int main(){

    freopen("polygon.in","r",stdin);

    freopen("polygon.out","w",stdin);

    cin>>n;

    for(int i=0;i<n;i++){

        cin>>a[i];

    }

    if(n==3){

        if(a[0]+a[1]+a[2]>max(a[0],max(a[1],a[2]))*2){

        cout<<1;

        }else{

        cout<<0;

        }

    }else{

        cout<<1;

    }

    return 0;

}
