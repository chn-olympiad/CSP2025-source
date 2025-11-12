#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],c,r,l;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    int f=a[1];
    for(int i=1;i<=m*n-1;i++){
        bool flag=true;
        for(int j=1;j<=m*n-i;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
                flag=false;
            }
        }
        if(flag==true) break;
    }
    for(int i=1;i<=m*n;i++){
        if(f==a[i]){
        l=i;
        break;
        }
    }
    int l1=l;
    while(l1>0){
        c++;
        l1-=n;
    }
    cout<<c<<" ";
    if(c%2==0) cout<<n*c-l+1;
    else cout<<l-(c-1)*n;
    return 0;
}
