#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,rc,c=0,r=0,t=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    rc=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
    }
    for(int i=m*n;i>0;i-=m){
        r=0;
        c++;
        for(int j=0;j<m;j++){
            r++;
            if(a[i-j]==rc){
                t=1;
                break;
            }

        }
        if(t==1)  break;
    }
    if(c%2==0)
        r=n-r+1;
    cout<<c<<' '<<r;
    return 0;
}
