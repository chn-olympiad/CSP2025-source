#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5010],cnt=0;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n-1;i>0;i-=1){
        for(int j=i;j>0;j-=1){
            if(a[j-1]<a[j]){
                int t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=0;i<n;i++){
        int m=1,n=2;
        for(int j=0;j<n;j++)
            if(a[i]+a[i+m]+a[i+n]>2*a[i+n])  cnt++;
            m++;
            n++;
    }
    cout<<cnt;
    return 0;
}
