#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int num=a[1];
    for(int i=0;i<n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[j]<a[j+1]){
                int x;
                x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
            }
        }
    }
    for(int i=1;i<=n*m;i++) if(num==a[i]) num=i;
    if(num%n==0) c=num/n;
    else c=num/n+1;
    if(c%2==0){
        if(num%n==0) r=1;
        else if(num%n==1) r=n;
        else r=n-(num%n)+1;
    }else{
        if(num%n==0) r=n;
        else if(num%n-1==0) r=n;
        else r=num%n-1;
    }
    cout<<c<<" "<<r;
    return 0;
}
