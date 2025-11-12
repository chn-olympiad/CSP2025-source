#include <bits/stdc++.h>
using namespace std;

int a[5000]={};
int main (){

    int n,cnt=0,maxn=0,sum=0;
    cin>>n;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    for(int i=3;i<=n;i++){
        cin>>a[i];
    }for(int i=3;i<=n;i++){
        if(a[i]>maxn){
            maxn==a[i];
        }
        sum+=a[i];
        cnt++;
    }
    cout<<cnt;
    return 0;
}
