#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;
int a[1000005];
int n;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    for(int i=0;i<n;i++){
            cin>>a[i];

    }
     for(int i=0;i<n;i++){
           cout<<a[i]+a[i+1];

    }

    return 0;

}

