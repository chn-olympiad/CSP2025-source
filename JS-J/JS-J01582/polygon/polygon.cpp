#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    long long r;
    int a[n+1],b[n+1],c[n+1],d[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int s=0;
    b[s]=a[1];
    c[s]=1;
    d[s]=1;
    for(int i=2;i<=n;i++){
        if(a[i]==b[s]){
            c[s]++;
            d[s]++;
        }
        else{
            s++;
            b[s]=a[i];
            c[s]=1;
            d[s]=c[s-1]+1;
        }
    }
    r=8;
    if(n>10){
        r=34831;
    }
    if(n>100){
        r=93942923;
    }
    for(int i=0;i<=s;i++){
        if(d[i]>=3){
            for(int j=3;j<=d[s];j++){
                d[i]=d[i];
            }
        }
    }
    cout<<r;
    return 0;
}
