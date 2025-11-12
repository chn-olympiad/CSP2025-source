#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int ans=a[1],num=0;
    for(int i=1;i<=n*m;i++){
        for(int j=2;j<=n*m;j++){
            c=max(a[j],a[j-1]),d=min(a[j],a[j-1]);
            a[j-1]=c,a[j]=d;
            c=0,d=0;
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]=ans){
            num=i;
        }
    }
    if(num%n==0){
        x=num/n;
    }else{
        x=num/n+1;
    }
    if(x%2!=0){
        y=num-n*(x-1);
    }else{
        if(num%n==0) y=n;
        else y=n-num+n*(x-1);
    }
    cout<<x<<" "<<y;
    return 0;
}
