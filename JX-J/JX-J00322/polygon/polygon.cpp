#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    int temp=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            temp++;
        }
    }
    cnt+=(n-temp)*(n-temp-1)*(n-temp-2)/6;
    for(int i=4;i<=n;i++){
        int x=1;
        for(int j=1;j<=i;j++){
            x*=n-j+1;
        }
        int y=1;
        for(int j=1;j<=i;j++){
            y*=j;
        }
        cnt+=x/y;
    }
    cout<<cnt%998244353;


    return 0;
}

